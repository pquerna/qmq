# Licensed to Cloudkick, Inc under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# libcloud.org licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


EnsureSConsVersion(1, 1, 0)

import os
from os.path import join as pjoin
from site_scons.util import read_version

opts = Variables('build.py')

env = Environment(options=opts,
                  ENV = os.environ.copy(),
                  tools=['default'])

env['version_major'], env['version_minor'], env['version_patch'] = read_version('QMQ', 'include/qmq_version.h')
env['version_string'] = "%d.%d.%d"  % (env['version_major'], env['version_minor'], env['version_patch'])

conf = Configure(env, custom_tests = {})

cc = conf.env.WhereIs('/Developer/usr/bin/clang')
if os.environ.has_key('CC'):
  cc = os.environ['CC']

if cc:
  conf.env['CC'] = cc

if not conf.CheckFunc('floor'):
  conf.env.AppendUnique(LIBS=['m'])

#TODO: move to opts
debug=1
if debug:
  conf.env.AppendUnique(CPPFLAGS = ["-Wall", '-O0', '-ggdb'])
else:
  conf.env.AppendUnique(CPPFLAGS = ["-Wall", '-O2', '-ggdb'])

# this is needed on solaris because of its dumb library path issues
conf.env.AppendUnique(RPATH = conf.env.get('LIBPATH'))
conf.env.AppendUnique(CPPPATH=['#include'])

env = conf.Finish()

Export("env")

qmq = SConscript("server/SConscript")['qmq']

targets = [qmq]
target_packages = []
# TODO: packaging
targets.extend(target_packages)

env.Default(targets)
