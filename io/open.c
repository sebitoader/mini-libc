// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	va_list valist;
	mode_t mode = 02;

	if(flags & O_CREAT) {
		va_start(valist, flags);
		mode = va_arg(valist, mode_t);
		va_end(valist);
		int ret = syscall(__NR_open, filename, flags, mode);
		if (ret < 0) {
			errno = -ret;
			return -1;
		}
		return ret;
	}
	int ret = syscall(__NR_open, filename, flags);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
