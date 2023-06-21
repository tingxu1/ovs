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

#ifndef __SWITCHLINK_ROUTE_H__
#define __SWITCHLINK_ROUTE_H__

extern void route_create(switchlink_handle_t vrf_h,
                         switchlink_ip_addr_t *dst,
                         switchlink_ip_addr_t *gateway,
                         switchlink_handle_t ecmp_h,
                         switchlink_handle_t intf_h,
                         switchlink_mac_addr_t mac_addr);

extern void route_delete(switchlink_handle_t vrf_h, switchlink_ip_addr_t *dst);

extern bool validate_nexthop_delete(uint32_t using_by,
                                    switchlink_nhop_using_by_e type);

void process_route_msg(struct nlmsghdr *nlmsg, int type);

#endif /* __SWITCHLINK_ROUTE_H__ */
