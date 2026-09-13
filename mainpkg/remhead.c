#include <stdio.h>
#include <stdlib.h>

char* remhead(char* path, int hl) {
    if (path == NULL) {
        return NULL;
    }
    return (path + hl);
}