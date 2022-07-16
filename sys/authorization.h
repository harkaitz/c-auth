#ifndef SYS_AUTHORIZATION_H
#define SYS_AUTHORIZATION_H

#include <string.h>
#include <stdbool.h>
#include <syslog.h>
#include <stdio.h>
#ifdef __GNUC__
#  define AUTHORIZATION_ATTRS_THREAD __thread __attribute__((weak))
#else
#  define AUTHORIZATION_ATTRS_THREAD __attribute__((weak))
#endif
#define AUTHORIZATION_ATTRS_GLOBAL __attribute__((weak))

/* --------------------------------------------------------------------------
 * ---- USERNAME STORAGE ----------------------------------------------------
 * -------------------------------------------------------------------------- */

typedef struct pam_handle pam_handle_t;

AUTHORIZATION_ATTRS_THREAD char        g_authorization[64]     = {0};
AUTHORIZATION_ATTRS_THREAD bool        g_authorization_is_root = false;
AUTHORIZATION_ATTRS_GLOBAL char const *AUTHORIZATION_ROOT_USERNAME;

static inline void
authorization_close (void) {
    memset(g_authorization, 0, sizeof(g_authorization));
}

static inline bool
authorization_open(const char _username[]) {
    strncpy(g_authorization, _username, sizeof(g_authorization)-1);
    g_authorization_is_root = 
        AUTHORIZATION_ROOT_USERNAME
        &&
        !strcmp(g_authorization, AUTHORIZATION_ROOT_USERNAME);
    return true;
}

static inline const char *
authorization_get_username(void) {
    return (g_authorization[0])?g_authorization:NULL;
}

static inline bool
authorization_user_is(const char _username[]) {
    if (g_authorization_is_root) {
        return true;
    } else if (!g_authorization[0]) {
        return false;
    } else if (!strcmp(g_authorization, _username)) {
        return true;
    } else {
        return false;
    }
}

static inline bool
authorization_user_is_root(void) {
    return g_authorization_is_root;
}



#endif
