#include<stdio.h>
#include<stdlib.h>

int main() {
    char buf[256];

    while (fgets(buf, sizeof buf, stdin)) {
        printf("READ: [%s]", buf);
    }

    return 0;

}