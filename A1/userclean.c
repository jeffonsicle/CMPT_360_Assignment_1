#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char buf[256];

    // move input from stdin to buf
    fgets(buf, sizeof buf, stdin);

    // Find the first occurrence of '\n' or '\r' and replace it with '\0'
    buf[strcspn(buf, "\n\r")] = '\0';

    // print the buf string followed by " : "
    printf("%s : ", buf);

    // checks if the buf char is root or admin, if it is print error and exit program
    if(strcmp(buf, "root") == 0 || strcmp(buf, "admin") == 0) {
        printf("invalid and unfixable\n");
        return 0;
    }

    // print a new line character
    printf("\n");
    return 0;

}