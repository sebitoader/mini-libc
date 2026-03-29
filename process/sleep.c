#include <internal/syscall.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    long result = syscall(__NR_nanosleep, &req, &rem);
    if (result == -1) {
        if (errno == EINTR) {
            return rem.tv_sec;
        }
        return seconds;
    }
    return 0;
}

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(__NR_nanosleep, req, rem);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
