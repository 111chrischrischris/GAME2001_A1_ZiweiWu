#pragma once
#include <cassert>
#include "BaseArray.h"

template <class T>
class OrderedArray : public BaseArray <T>
{
public:
	OrderedArray(int size, int growBy = 1) :
		BaseArray<T>(size, growBy)
	{

	}
	~OrderedArray()
	{
		if (BaseArray<T>::m_array != NULL)
		{
			delete[] BaseArray<T>::m_array;
			BaseArray<T>::m_array = NULL;		
		}
	}
	int push(T val)
	{

		assert(BaseArray<T>::m_array != NULL);

		if (BaseArray<T>::m_numElements >= BaseArray<T>::m_maxSize)
		{
			BaseArray<T>::Expand();
		}

		int i, k;
		for (i = 0; i < BaseArray<T>::m_numElements; i++)
		{
			if (BaseArray<T>::m_array[i] == val)
			{
				return -1;
			}

			if (BaseArray<T>::m_array[i] > val)
			{
				break;
			}
		}

		for (k = BaseArray<T>::m_numElements; k > i; k--)	
		{
			BaseArray<T>::m_array[k] = BaseArray<T>::m_array[k - 1];
		}

		BaseArray<T>::m_array[i] = val;

		BaseArray<T>::m_numElements++;

		return i;
	}

	const T& operator[](int index)
	{
		assert(BaseArray<T>::m_array != NULL && index < BaseArray<T>::m_numElements);
		return BaseArray<T>::m_array[index];
	}
	void clear()
	{
		BaseArray<T>::m_numElements = 0;
	}
	int GetSize()
	{
		return BaseArray<T>::m_numElements;
	}
	int GetMaxSize()
	{
		return BaseArray<T>::m_maxSize;
	}
	int GetGrowSize()
	{
		return BaseArray<T>::m_growSize;
	}
	void SetGrowSize(int val)
	{
		assert(BaseArray<T>::val >= 0);
		BaseArray<T>::m_growSize = val;
	}
private:
	int search(T searchKey)
	{
		assert(BaseArray<T>::m_array != NULL);

		int lowerBound = 0;
		int upperBound = BaseArray<T>::m_numElements - 1;
		int current = 0;

		while (1)   
		{
			current = (lowerBound + upperBound) >> 1; 

			if (BaseArray<T>::m_array[current] == searchKey)
			{
				return current;
			}
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				if (BaseArray<T>::m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}

		return -1;
	}

};
