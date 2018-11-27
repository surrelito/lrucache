#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node
{
	int id;
    char *txt;
	struct Node *next;
};

typedef struct 
{
	struct Node *head;
	int counter;
}LinkedList;


