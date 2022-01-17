/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <stdio.h>
#include <zephyr.h>

#include "handlers.h"

void main(void)
{
	wifi_handler_connect(true);
	bt_handler_init();
	bt_handler_set_sampling_interval(1000);
	while(mqtt_handler_connect())
	{
		k_msleep(1000);
	}

	while(true)
	{
		if(bt_handler_fetch_data())
		{
			break;
		}
        // bt_get_temp() returns the last correct reading
		if(mqtt_handler_publish(bt_get_temp()))
		{
			break;
		}
		k_msleep(10000);
	}

	mqtt_handler_disconnect();

}