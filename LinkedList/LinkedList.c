#include <stdlib.h>

typedef struct Node
{
	int id;
	char *txt;
	struct Node *next;
}Node;

typedef struct LinkedList
{
	struct node *head;
}LinkedList;

void addToLinkedList(struct LinkedList *linkedList, int id, char *txt)
{
	Node *newNode = NULL;
	newNode = malloc(sizeof(Node));
	newNode->id = id;
	newNode->txt = txt;
	newNode->next = linkedList->head;
	linkedList->head = newNode->next;

}