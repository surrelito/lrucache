#include "LRUCACHE.h"
#include <iostream>


std::string LRUCACHE::Get(int id)
{
	int indexCounter{};
	struct Node *current = linkedList.head;
	struct Node *previous = NULL;
	if (linkedList.counter < 0)
	{
		linkedList.head = NULL;
		linkedList.counter = 0;
	}
	else {
		while (current != NULL) {
			printf("Looking for %d : ", id);
			printf("\n");
			indexCounter++;
			if (current->id == id) {
				printf("In node %d : * * Search %d ** Found CITY %s :", current->id, id, current->txt);
				printf("\n");
				if (indexCounter <= 1) {
					return linkedList.head->txt;
				}
				else {
					previous->next = current->next;
					current->next = linkedList.head;
					linkedList.head = current;
					return linkedList.head->txt;
				}
			}
			else {
				previous = current;
				current = current->next;
			}
		}
	}
	return "";
}
void LRUCACHE::Add(int id, std::string destination)
{
	if (GetLRUcacheSize() >= LRUcacheMaxSize) {
		Delete();
		SetLRUcacheSize(-1);
	}
	AddToLinkedList(&linkedList, id, destination.c_str());
	SetLRUcacheSize(1);
}
void LRUCACHE::Delete()
{
	DeleteLastNode(&linkedList);
}
void LRUCACHE::SetLRUcacheSize(int set) {
	if (set == -1)
		this->LRUcacheSize -= 1;
	else
		this->LRUcacheSize += 1;
}
void LRUCACHE::Print()
{
	PrintLinkedlist(&linkedList);
}
