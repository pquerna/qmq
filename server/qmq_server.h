/*
 * Licensed to Cloudkick, Inc under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * libcloud.org licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>
#include <vector>

#ifndef _qmq_server_h_
#define _qmq_server_h_

typedef struct qmq_serv_listener_t {
  std::string address;
  int port;
} qmq_serv_listener_t;

typedef struct qmq_serv_conf_t {
  int thread_count;
  std::vector<qmq_serv_listener_t> listeners;
} qmq_serv_conf_t;

#endif
