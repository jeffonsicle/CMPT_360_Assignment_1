# CMPT_360_Assignment_1

Student Name: Jeffrey Moniz
Student ID: 3148591
Submission Date: 
File Name: README.md

This program is designed to take a user name and check if it is valid, if it is not valid the program will try to clean the username to make it valid, otherwise the program will output an error message. 

I first took the input from the user and converted it to a character using fgets(), I also removed the newline character and replaced it with the \0 character. I set an if statement that checks to make sure that the input is not root, admin, or that it does not start with _, if the input is one of these than the program will output the invalid message

I then set up an for loop that will go through each of the characters in the input and check if the character is an uppercase, check if the length is less than 3 characters, check if there are any spaces, and check if the length exceeds 16. If any of these occur the program will fix it accordingly

at the end, the program will print the updated user name