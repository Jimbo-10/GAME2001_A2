#pragma once
#include "LinkList.h"

template<class T, class CMP>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	void push(T val)
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push(val);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			CMP cmp;	

			while (it.isValid())
			{
				if (cmp(val, *it))
				{
					break;	
				}

				it++;
			}

			if (it.isValid())
			{
				m_elements.Insert(it, val);
			}
			else
			{
				m_elements.Push(val);
			}
		}
	}

	void pop()
	{
		m_elements.Pop();
	}

	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it;
	}

	int GetSize()
	{
		return m_elements.GetSize();
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

private:
	LinkedList<T> m_elements; 
	int m_size;
};