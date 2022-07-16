#include "sys/authorization.h"
#include <stdio.h>

void eat_cake(int val1, const char *message) {
    if (!authorization_check(eat_cake, val1, message)) return;
    fprintf(stdout, "%i: Ate a cake, %s\n", val1, message);
}

bool eat_cake_auth (int val1, const char *message) {
    if (val1>3) {
        fprintf(stderr, "%i: Not allowed.\n", val1);
        return false;
    } else {
        return true;
    }
}

struct authorization_s AUTHORIZATION_FUNCS[] = {
    { eat_cake, eat_cake_auth },
    { NULL    , NULL}
};

int main (void) {
    eat_cake(1, "mmmmm");
    eat_cake(2, "mmmmm");
    eat_cake(3, "mmmmm");
    eat_cake(4, "mmmmm");
    eat_cake(5, "mmmmm");
    return 0;
}
