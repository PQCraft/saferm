#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dirct(char* str) {
    int ct = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '/') ct++;
    }
    if (strlen(str) != 1 && str[strlen(str) - 1] == '/') ct --;
    return ct;
}

int main(int argc, char* argv[]) {
    char* command;
    int len = 1;
    char* dir = getcwd(NULL, 0);
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];
        if ((!strcmp(dir, "/") && dirct(arg) == 0) || (arg[0] == '/' && dirct(arg) == 1)) {
            puts("Unsafe action detected."); exit(EXIT_FAILURE);
        }
        len += strlen(arg);
    }
    command = malloc(len);
    strcpy(command, "rm");
    for (int i = 1; i < argc; i++) {
        strcat(command, " ");
        strcat(command, argv[i]);
    }
    return system(command);
}