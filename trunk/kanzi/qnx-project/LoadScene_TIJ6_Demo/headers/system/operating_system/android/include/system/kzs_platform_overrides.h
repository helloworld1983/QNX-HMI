/**
 * \file
 * Platform overrides for the Android platform
 * 
 * Copyright 2008-2014 by Rightware. All rights reserved.
 */
#ifndef KZS_PLATFORM_OVERRIDES_H
#define KZS_PLATFORM_OVERRIDES_H


#include <system/kzs_header.h>


KZ_HEADER_BEGIN


/** Overrides kzsLogCreateDefaultLoggers from system/debug/kzs_log.c */
#define KZS_OVERRIDE_LOG_CREATE_DEFAULT_LOGGERS


KZ_HEADER_END


#endif
