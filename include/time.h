/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
#include <internal/essentials.h>

#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC 0
#endif

typedef long time_t;

struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
