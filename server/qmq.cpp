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

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#include "qmq_server.h"

#include "qmq_version.h"

static void show_version()
{
#ifdef QMQ_IS_DEV
  const char *extra = "-dev";
#else
  const char *extra = "";
#endif
  fprintf(stdout, "qmq - %d.%d.%d%s\n", QMQ_VERSION_MAJOR,
          QMQ_VERSION_MINOR, QMQ_VERSION_PATCH, extra);
  exit(EXIT_SUCCESS);
}

static void show_help()
{
  fprintf(stdout, "qmq - Cloudkick's Quick Message Queue\n");
  fprintf(stdout, "  Usage:  \n");
  fprintf(stdout, "    ckl [-h|-V]\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "     -h          Show Help message\n");
  fprintf(stdout, "     -V          Show Version number\n");
  exit(EXIT_SUCCESS);
}


static void error_out(const char *msg) {
  fprintf(stderr, "ERROR: %s\n\n", msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char *const *argv)
{
  int c;
  while ((c = getopt(argc, argv, "hV")) != -1) {
    switch (c) {
      case 'V':
        show_version();
        break;
      case 'h':
        show_help();
        break;
      case '?':
        error_out("See -h for correct options");
        break;
    }
  }

  exit(EXIT_SUCCESS);
}
