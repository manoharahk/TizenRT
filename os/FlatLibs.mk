###########################################################################
#
# Copyright 2016 Samsung Electronics All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
# either express or implied. See the License for the specific
# language governing permissions and limitations under the License.
#
###########################################################################
############################################################################
# FlatLibs.mk
#
#   Copyright (C) 2007-2012, 2014 Gregory Nutt. All rights reserved.
#   Author: Gregory Nutt <gnutt@nuttx.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name NuttX nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

# TIZENRTLIBS is the list of TizenRT libraries that is passed to the
#   processor-specific Makefile to build the final TizenRT target.
#   Libraries in FSDIRS are excluded if file descriptor support
#   is disabled.
# USERLIBS is the list of libraries used to build the final user-space
#   application
# EXPORTLIBS is the list of libraries that should be exported by
#   'make export' is

TIZENRTLIBS = $(LIBRARIES_DIR)$(DELIM)libkernel$(LIBEXT)
USERLIBS =

# Add libraries for syscall support.

TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libc$(LIBEXT) $(LIBRARIES_DIR)$(DELIM)libmm$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libarch$(LIBEXT)
ifeq ($(CONFIG_LIB_SYSCALL),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libstubs$(LIBEXT)
USERLIBS  += $(LIBRARIES_DIR)$(DELIM)libproxies$(LIBEXT)
endif

# Add libraries for C++ support.  CXX, CXXFLAGS, and COMPILEXX must
# be defined in Make.defs for this to work!

ifeq ($(CONFIG_HAVE_CXX),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libcxx$(LIBEXT)
endif

# Add library for application support.

ifneq ($(APPDIR),)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libapps$(LIBEXT)
endif

# Add library for external support.

TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libexternal$(LIBEXT)

# Add libraries for network support

ifeq ($(CONFIG_NET),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libnet$(LIBEXT)
endif

# Add libraries for iotivity support
ifeq ($(CONFIG_ENABLE_IOTIVITY),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)liboctbstack$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libc_common$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libconnectivity_abstraction$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libcoap$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)liblogger$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libocsrm$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libroutingmanager$(LIBEXT)
ifeq ($(CONFIG_ENABLE_IOTIVITY_CLOUD),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libresource_directory$(LIBEXT)
endif
endif

# Add libraries for power management module

ifeq ($(CONFIG_PM),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libpm$(LIBEXT)
endif

# Add libraries for logm module

ifeq ($(CONFIG_LOGM),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)liblogm$(LIBEXT)
endif

# Add libraries for file system support

ifeq ($(CONFIG_NFILE_DESCRIPTORS),0)
ifneq ($(CONFIG_NSOCKET_DESCRIPTORS),0)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libfs$(LIBEXT)
endif
ifeq ($(CONFIG_NET),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libdrivers$(LIBEXT)
endif
else
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libfs$(LIBEXT) $(LIBRARIES_DIR)$(DELIM)libdrivers$(LIBEXT)
endif

# Add libraries for the Audio sub-system

ifeq ($(CONFIG_AUDIO),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libaudio$(LIBEXT)
endif

# Add library for Framework
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libframework$(LIBEXT)

# Add libraries for iotjs support
ifeq ($(CONFIG_ENABLE_IOTJS),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libhttpparser$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libiotjs$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libjerry-core$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libtuv$(LIBEXT)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libjerry-libm$(LIBEXT)
endif

# Add library for external bcm support.
# External WICED Lib builds
ifeq ($(CONFIG_WL_BCM4390X),y)
TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)libbcmexternal$(LIBEXT)
endif

# Export all libraries
EXPORTLIBS = $(TIZENRTLIBS)

