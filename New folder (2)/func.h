#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#ifdef WIN32
#define CLS "cls"
#else
#define CLS "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ENTER 13
#define TAB 9
#define BKSPC 8

void intro();
void user_input(char ch[50]);
void detail_input(char ch2[200]);
void pwd_input(char pwd[50]);
void login(char username[50], char pwd[50]);
int option_display();

#endif
