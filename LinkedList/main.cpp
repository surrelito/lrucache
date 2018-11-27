#include <iostream>
#include "DisplayMessageEndpoint.h"
#include "LRUCACHE.h"
#include <Windows.h>
#include "LinkedList.h"

std::string GetDestinationFrom(int destinationId, LRUCACHE *LruCache)
{
	std::string destination = LruCache->Get(destinationId);
	if (destination.size() != NULL) {
		return destination;
	}
	else {
		DisplayMessageDestinationService service;
		destination = service.GetDestinationName(destinationId);
		LruCache->Add(destinationId, destination);
		return destination;
	}
}
int main()
{
	int count{};
	SetConsoleOutputCP(1252);
	LRUCACHE *lrucache = new LRUCACHE;
	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();

	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, lrucache)
			<< std::endl;
		count++;
		if (count > 1) {
			std::cout << std::endl;
			std::cout << "*********LRUCACHE*********" << std::endl;
			lrucache->Print();
			std::cout << "*********LRUCACHE*********" << std::endl;
			std::cout << std::endl;
		}

	}
}