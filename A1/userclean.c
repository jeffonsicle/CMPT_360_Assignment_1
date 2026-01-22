/*
Student Name: Jeffrey Moniz
Student ID: 3148591
Submission Date: January 22nd 2026
File Name: userclean.c
Description: This program reads a username from standard input, cleans it by converting uppercase letters to lowercase,
             replacing whitespace with underscores, and removing invalid characters. If the username is "root" or
             "admin", it prints an error message. Finally, it outputs the cleaned username.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
    char buf[256];

    if (argc == 2) {
        /* Read from command-line argument */
        strncpy(buf, argv[1], sizeof buf - 1);
        buf[sizeof buf - 1] = '\0';
    } else if (argc == 1) {
        /* Read from stdin */
        if (fgets(buf, sizeof buf, stdin) == NULL) {
            fprintf(stderr, "Input error\n");
            return 1;
        }
        buf[strcspn(buf, "\n\r")] = '\0';
    } else {
        fprintf(stderr, "Usage: %s [username]\n", argv[0]);
        return 1;
    }

    // print the buf string followed by " : "
    printf("%s : ", buf);

    // checks if the buf char is root or admin, if it is print error and exit program
    if(strcmp(buf, "root") == 0 || strcmp(buf, "admin") == 0 || buf[0] == '_') {
        printf("invalid and unfixable\n");
        return 0;
    }

    CharCheck(buf);

    // print the cleaned buf string
    printf("%s", buf);

    // print a new line character
    printf("\n");
    return 0;

}

void CharCheck(char buf[256])
{
    for(int i = 0; buf[i] != '\0'; i++) {
        // if uppercase convert to lowercase
        if(buf[i] >= 'A' && buf[i] <= 'Z') {
            buf[i] = buf[i] + ('a' - 'A');
            //if the length exceeds 16 characters truncate it
            if(i >= 16) {
                buf[i] = '\0';
                break;
            }
            //check if the next element is \0 and the length is less than 3, if it is add elements from 'user'
            if(buf[i + 1] == '\0' && i < 2) {
                const char* suffix = "user";
                for(int j = 0; j < 4 && i < 15; j++, i++) {
                    buf[i + 1] = suffix[j];
                }
                buf[i + 1] = '\0'; // null-terminate the string
            }
        }
        // else if whitespace replace with underscore
        else if(buf[i] == ' ' || buf[i] == '\t') {
            buf[i] = '_';
            //if the length exceeds 16 characters truncate it
            if(i >= 16) {
                buf[i] = '\0';
                break;
            }
            //check if the next element is \0 and the length is less than 3, if it is add elements from 'user'
            if(buf[i + 1] == '\0' && i < 2) {
                const char* suffix = "user";
                for(int j = 0; j < 4 && i < 15; j++, i++) {
                    buf[i + 1] = suffix[j];
                }
                buf[i + 1] = '\0'; // null-terminate the string
            }
        }
        // else if invalid character remove or skip it
        else if(!( (buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= '0' && buf[i] <= '9') || buf[i] == '_' )) {
            // shift all characters to the left to remove the invalid character
            for(int j = i; buf[j] != '\0'; j++) {
                buf[j] = buf[j + 1];
            }
            i--; // adjust index to account for removed character

            //if the length exceeds 16 characters truncate it
            if(i >= 16) {
                buf[i] = '\0';
                break;
            }

            //check if the next element is \0 and the length is less than 3, if it is add elements from 'user'
            if(buf[i + 1] == '\0' && i < 2) {
                const char* suffix = "user";
                for(int j = 0; j < 4 && i < 2; j++, i++) {
                    buf[i + 1] = suffix[j];
                }
                buf[i + 1] = '\0'; // null-terminate the string
            }
        }
    }
}