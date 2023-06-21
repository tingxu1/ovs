/* INTEL CONFIDENTIAL
 *
 * Copyright (C) 2023 Intel Corporation
 * 
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you ("License"). Unless the License provides otherwise,
 * you may not use, modify, copy, publish, distribute, disclose or transmit
 * this software or the related documents without Intel's prior written permission.
 * 
 * This software and the related documents are provided as is, with no express or
 * implied warranties, other than those that are expressly stated in the License.
 */

/*
 * Copyright (c) 2013-2021 Barefoot Networks, Inc.
 * Copyright (c) 2022 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __SWITCH_PD_ROUTING_H__
#define __SWITCH_PD_ROUTING_H__

#include "switch_base_types.h"
#include "switch_handle.h"
#include "switch_l3.h"
#include "switch_rmac_int.h"
#include "switch_nhop.h"

#ifdef  __cplusplus
extern "C" {
#endif

/** enum to decide the proper key and action based on ecmp or nhop
 * */
typedef enum switch_pv4_table_action_s
{
  SWITCH_ACTION_NHOP = 0,
  SWITCH_ACTION_NHOP_GROUP = 1,
  SWITCH_ACTION_NONE = 2
}switch_ipv4_table_action_t;

typedef enum switch_route_v4_table_action_s
{
  SWITCH_ACTION_FORWARD_V4 = 0,
  SWITCH_ACTION_LOCAL_IN_V4 = 1,
}switch_route_v4_table_action_t;

typedef enum switch_route_v6_table_action_s
{
  SWITCH_ACTION_FORWARD_V6 = 0,
  SWITCH_ACTION_LOCAL_IN_V6 = 1,
}switch_route_v6_table_action_t;

/**
 * create pd_routing structure to hold
 * the data to be sent to
 * the backend to update the table */
typedef struct switch_pd_routing_info_s
{
  switch_handle_t neighbor_handle;

  switch_handle_t nexthop_handle;

  switch_handle_t rif_handle;

  switch_mac_addr_t dst_mac_addr;

  switch_port_t port_id;
  switch_port_t phy_port_id;

} switch_pd_routing_info_t;

switch_status_t switch_pd_nexthop_table_entry(
    switch_device_t device,
    const switch_pd_routing_info_t  *api_nexthop_pd_info,
    bool entry_add);

switch_status_t switch_pd_route_forward_v4_table_entry(
    switch_device_t device,
    const switch_pd_routing_info_t  *api_nexthop_pd_info,
    bool entry_add);

switch_status_t switch_pd_route_forward_v6_table_entry(
    switch_device_t device,
    const switch_pd_routing_info_t  *api_nexthop_pd_info,
    bool entry_add);

switch_status_t switch_pd_neighbor_table_entry(
    switch_device_t device,
    const switch_pd_routing_info_t  *api_neighbor_pd_info,
    bool entry_add);

switch_status_t switch_pd_rmac_table_entry (
    switch_device_t device,
    switch_rmac_entry_t *rmac_entry,
    switch_handle_t rif_handle,
    bool entry_type);

switch_status_t switch_pd_rif_mod_entry(
    switch_device_t device,
    switch_rmac_entry_t *rmac_entry,
    switch_handle_t rif_handle,
    bool entry_add);

switch_status_t switch_pd_ipv4_table_entry (switch_device_t device,
    const switch_api_route_entry_t *api_route_entry,
    bool entry_add, switch_ipv4_table_action_t action);
switch_status_t switch_routing_table_entry (
        switch_device_t device,
        const switch_pd_routing_info_t *api_routing_info,
        bool entry_type);
switch_status_t switch_pd_srv6_ipv6_table_entry (switch_device_t device,
    const switch_api_route_entry_t *api_route_entry,
    bool entry_add, switch_route_v6_table_action_t action);
switch_status_t switch_pd_handle_member(switch_device_t device,
    const switch_nhop_member_t *nhop_member_pd_info,
    bool entry_add);

switch_status_t switch_pd_srv6_ipv4_table_entry (switch_device_t device,
    const switch_api_route_entry_t *api_route_entry,
    bool entry_add, switch_route_v4_table_action_t action);

switch_status_t switch_pd_handle_group(switch_device_t device,
    switch_nhop_group_info_t *nhop_group_pd_info,
    bool entry_add);

#ifdef  __cplusplus
}
#endif

#endif 