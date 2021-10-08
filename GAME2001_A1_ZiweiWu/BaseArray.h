#pragma once
#include <cassert>
template <class T>
class BaseArray
{
public:
    BaseArray(int size, int growBy = 1) :
        m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
    {
        if (size)
        {
            m_maxSize = size;
            m_array = new T[m_maxSize];   
            memset(m_array, 0, sizeof(T) * m_maxSize);

            m_growSize = ((growBy > 0) ? growBy : 0);
        }
    }
    ~BaseArray()
    {
        if (m_array != NULL)
        {
            delete[] m_array;
            m_array = NULL;
        }
    }
    void pop()
    {
        if (m_numElements > 0)
        {
            m_numElements--;
        }
    }
    void remove(int index)
    {
        assert(m_array != NULL);

        if (index >= m_numElements)
        {
            return;
        }

        for (int i = index; i < m_numElements; i++)
        {
            if (i + 1 < m_numElements)
            {
                m_array[i] = m_array[i + 1];
            }
        }

        m_numElements--;
    }
protected:
    bool Expand()
    {
        if (m_growSize <= 0)
        {
            return false;
        }

        T* temp = new T[m_maxSize + m_growSize];
        assert(temp != NULL);

        memcpy(temp, m_array, sizeof(T) * m_maxSize);

        delete[] m_array;
        m_array = temp;
        temp = NULL;

        m_maxSize += m_growSize;
        m_growSize *= 2;

        return true;
    }
public:
    void clear()
    {
        m_numElements = 0;
    }
    int getSize()
    {
        return m_numElements;
    }
    int getMaxSize()
    {
        return m_maxSize;
    }
    void setMaxSize(int size)
    {
        m_maxSize = size;
    }
    int getGrowSize()
    {
        return m_growSize;
    }
    void setGrowSize(int val)
    {
        assert(val >= 0);
        m_growSize = val;
    }

    T* m_array;

    int m_maxSize;
    int m_growSize = 2;
    int m_numElements;
};
