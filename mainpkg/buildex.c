#include "findfiles.c"

int main() {
    const char* path = "."; // Specify the directory path with wildcard
    char* fout[100]; // Array to store found file paths
    FindAllFiles(path, fout, 0);
    for (int i = 0; i < 100; i++) {
        printf("debug\n");
        printf("Found file: %s\n", fout[i]);
    }
    free(fout);
    return 0;
}