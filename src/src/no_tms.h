#ifndef _NO_TMS__H_
#define _NO_TMS__H_

#include "local_config.h"
#include <stdlib.h>
#include <stdio.h>

#define tms_infof(...)
#define tms_warnf(...)
#define tms_fatalf(...)
#define tms_errorf(...)
#define tms_printf(f, ...) fprintf(stdout, f, ##__VA_ARGS__); fflush(stdout);
#define tms_debugf(...)
#define tms_assertf(expr, f, ...) {if (expr);else tms_fatalf(f, ##__VA_ARGS__);}

static const char *tbackend_get_storage_path(){return STATIC_STORAGE_PATH;};

static inline int
_fatal_exit() {
    exit(1);
    return 0;
}

#endif
