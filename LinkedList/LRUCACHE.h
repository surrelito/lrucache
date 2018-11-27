#pragma once
#include "LinkedList.h"
#include <string>


class LRUCACHE
{
public:
	std::string Get(int id);
	void Add(int id, std::string name);
	void Print();
	void Delete();
	void SetLRUcacheSize(int set);
	int GetLRUcacheSize() { return this->LRUcacheSize; }
	const int LRUcacheMaxSize = 10; //NEW

private:
	LinkedList linkedList;
	int LRUcacheSize = 0;
};

extern "C" void AddToLinkedList(LinkedList *linkedList, int id, const char *txt);
extern "C" void PrintLinkedlist(LinkedList *linkedList);
extern "C" void DeleteLastNode(LinkedList *linkedList);
