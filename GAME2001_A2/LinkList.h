#pragma once
#include <cassert>

template <class T> class LinkIterator;
template <class T> class LinkedList;

template <class T>
class Node
{
public:
	friend class LinkIterator<T>;
	friend class LinkedList<T>;

private:
	int priority;
	T data;
	Node* next;
	Node* prev;	
};

template <class T>
class LinkIterator
{
public:
	friend class LinkedList<T>;

	LinkIterator()
	{
		m_node = nullptr;
	}
	~LinkIterator() {}
	
	void operator=(Node<T>* node)
	{
		m_node = node;
	}
	
	T& operator*()
	{
		assert(m_node != nullptr);
		return m_node->data;
	}
	
	void operator++()	
	{
		assert(m_node != nullptr);
		m_node = m_node->next;
	}
	void operator++(int) 
	{
		assert(m_node != nullptr);
		m_node = m_node->next;
	}
	
	void operator--()	
	{
		assert(m_node != nullptr);
		m_node = m_node->prev;
	}
	void operator--(int)	
	{
		assert(m_node != nullptr);
		m_node = m_node->prev;
	}
	
	bool operator!=(Node<T>* node)
	{
		return (m_node != node);
	}
	bool operator==(Node<T>* node)
	{
		return (m_node == node);
	}
	bool isValid()
	{
		return (m_node != NULL);
	}

private:
	Node<T>* m_node;	
};

template <class T>
class LinkedList
{
public:
	
	LinkedList() : size(0), rootNode(nullptr), m_lastNode(nullptr) {}
	~LinkedList(){}
	
	
	Node<T>* Begin()
	{
		assert(rootNode != nullptr);
		return rootNode;
	}
	Node<T>* End()
	{
		return nullptr;
	}
	Node<T>* Last()
	{
		assert(m_lastNode != nullptr);
		return m_lastNode;
	}

	void Push(T newData)
	{
		
		Node<T>* node = new Node<T>;

		assert(node != nullptr);
		node->data = newData;
		node->next = nullptr;
		node->prev = nullptr;

		if (rootNode != nullptr) 
		{
			node->next = rootNode;
			rootNode->prev = node;
			rootNode = node;
		}
		else 
		{
			rootNode = node;
			m_lastNode = node;
		}

		size++;
	}

	void Pop()
	{
		assert(rootNode != nullptr);
	
		Node<T>* temp = rootNode;

		rootNode = rootNode->next;

		if (rootNode != nullptr)
		{
			rootNode->prev = nullptr;
		}
		else
		{
			m_lastNode = nullptr;
		}

		delete temp;
		temp = nullptr;

		size = (size == 0 ? size : size - 1);
	}

	void Insert(LinkIterator<T>& it, T newData)
	{
		assert(it.m_node != nullptr);

		Node<T>* node = new Node<T>;
		assert(node != nullptr);

		node->data = newData;
		node->next = it.m_node;
		node->prev = it.m_node->prev;

		if (node->prev != nullptr)
		{
			node->prev->next = node;
		}

		it.m_node->prev = node;

		if (it.m_node == rootNode)
		{
			rootNode = node;
		}

		size++;
	}

	int GetSize()
	{
		return size;
	}

private:
	int size;				
	Node<T>* rootNode;	
	Node<T>* m_lastNode;
};
