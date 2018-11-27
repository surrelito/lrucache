#include "LinkedList.h"
#include <Windows.h>

void AddToLinkedList(LinkedList *linkedList, int id, const char *txt)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->id = id;
	newNode->txt = malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newNode->txt, txt);
	//linkedList->counter += 1;

	if (linkedList->head == NULL) {
		{
			linkedList->head = newNode;
			newNode->next = NULL;
		}
	}
	else {
		newNode->next = linkedList->head;
		linkedList->head = newNode;
	}
}
void DeleteLastNode(LinkedList *linkedList)
{
	Node* temp = linkedList->head;
	Node* t = NULL;
	while (temp->next != NULL) {
		t = temp;
		temp = temp->next;
	}
	printf("DELETED : %s", temp->txt);
	printf("\n");
	//Sleep(1500);
	//free(temp->txt);
	//temp->txt = NULL;
	//free(t->next);
	//t->next = NULL;
	//linkedList->counter -= 1;

}
void PrintLinkedlist(LinkedList *linkedList)
{
	Node * tempnode = linkedList->head;
	while (tempnode != NULL) {
		printf("*\t%s  %d\t *\n", tempnode->txt,tempnode->id);
		tempnode = tempnode->next;
	}
}