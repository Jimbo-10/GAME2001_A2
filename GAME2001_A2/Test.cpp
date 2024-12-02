#include <iostream>
#include "Priorityqueue.h"
using namespace std;

template<class T>
class less_cmp 
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return lVal < rVal;
	}
};

template<class T>
class less_cmp_pointer 
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return ((*lVal) < (*rVal));
	}
};

template<class T>
class greater_cmp 
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !(lVal < rVal);
	}
};

template<class T>
class greater_cmp_pointer 
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !((*lVal) < (*rVal));
	}
};

class NetworkMessage
{
public:
	NetworkMessage() : priority(0), id(0) {}
	NetworkMessage(int p, int id) : priority(p), id(id) {}
	~NetworkMessage() {}

	int GetPriority()
	{
		return priority;
	}
	int GetID()
	{
		return id;
	}

	// Overload operator
	bool operator<(NetworkMessage& m)
	{
		// Check the priority level of both network messages
		if (priority < m.GetPriority())
		{
			return true;
		}
		else if (id < m.GetID())
		{
			return true;
		}

		return false;
	}
	bool operator>(NetworkMessage& m)
	{
		return !(*this < m);	
	}
private:
	int priority;
	int id;
};

int main()
{
	cout << "Priority queue elements!" << endl << endl;

	const int SIZE = 4;
	PriorityQueue<NetworkMessage, less_cmp<NetworkMessage>> que(SIZE);

	que.push(NetworkMessage(4, 200));
	que.push(NetworkMessage(1, 460));
	que.push(NetworkMessage(7, 555));
	que.push(NetworkMessage(6, 240));

	cout << "Priority queue elements size: " << que.GetSize() << endl;

	while (que.isEmpty() == false)
	{
		cout << "  Priority: " << que.front().GetPriority();
		cout << "  ID: " << que.front().GetID();
		cout << endl;

		que.pop();
	}

	cout << endl;

	if (que.isEmpty() == true)
	{
		cout << "The container is empty." << endl;
	}
	else
	{
		cout << "The container is NOT empty." << endl;
	}

	return 0;
}