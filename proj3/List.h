#pragma once
#include <iostream>
#include <iterator>
template <typename T>
class List
{
public:
	List();
	void push_back(T data);
	void push_front(T data);
	T& operator[](const int index);
	void pop_front();
	void pop_back();
	void insert(const T &data, const int index);
	void remove_at(int index);
	int size() const;
	T& getFirst();
	T& getLast();
	bool isContains(T &data) const;
	bool isEmpty() const;
	void print() const;
	void clear();
	~List();
protected:
	template <typename T>
	class Node
	{
	public:
		Node(T data = T(), Node* Next = nullptr)
		{
			this->data = data;
			this->Next = Next;
		}
			
			Node *Next;
			T data;
			
	};
protected:	
	int Size;
	Node<T>* Head;
};

template<typename T>
List<T>::List()
{
	this->Size = 0;
	this->Head = nullptr;
}
template<typename T>
void List<T>::push_back(T data)
{
	if (Head==nullptr)
	{
		Head = new Node<T>(data);
	}
	else
	{
		Node <T> *current = Head;
		while (current->Next != 0)
		{
			current =current->Next;
		}
		current->Next = new Node<T>(data);
	}
	Size++;
}
template<typename T>
void List<T>::push_front(T data)
{
	Node<T> *newNode = new Node<T>(data);
	newNode->Next = Head;
	Head = newNode;
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	if (this->size() - 1 < index || index < 0) {
		throw std::out_of_range("out_of_range");
	}
	int counter = 0;
	Node<T>* current = Head;
	while (current!= nullptr)
	{
		if (index == counter) { return current->data; }
		current = current->Next;
		++counter;
	}
}
template<typename T>
void List<T>::pop_front()
{
	Node<T> *current = Head;
	Head = Head->Next;
	delete current;
	--Size;
}
template<typename T>
void List<T>::pop_back()
{
	remove_at(Size);
}
template<typename T>
void List<T>::insert(const T& data, const int index)
{ 
	if (index == 0) { push_front(data); }
	else
	{
		Node<T>* current = Head;
		while (Size - 1 > index) { current = current->Next;}
		current->Next = new Node<T>(data, current->Next);
		++Size;
	}
}
template<typename T>
void List<T>::remove_at(int index)
{
	if (index == 0) { pop_front(); --Size; }
	else
	{
		Node<T> *previous = this->Head;
		for(int i=0;i<index-1;++i)
		{
			previous = previous->Next;
		}
		Node<T> *toDel = previous->Next;
		previous->Next = toDel->Next;
		delete toDel;
		--Size;
	}
}
template<typename T>
int List<T>::size() const
{
	return this->Size;
}
template<typename T>
inline T& List<T>::getFirst()
{
	if (!isEmpty()) 
	{
		return (*this)[0];
	}
	else
	{
		throw std::logic_error("list is empty");
	}
}
template<typename T>
inline T& List<T>::getLast()
{
	if (!isEmpty())
	{
		return this[Size];
	}
	else
	{
		throw std::logic_error("list is empty");
	}
}
template<typename T>
inline bool List<T>::isContains(T& data) const
{
	Node<T>* current = Head;
	while (current != nullptr)
	{
		if(current->data==data)
		{
			return true;
		}
		current = current->Next;
	}
	return false;
}
template<typename T>
inline bool List<T>::isEmpty() const
{
	return !(Size>0);
}
template<typename T>
void List<T>::print() const
{
	Node<T>* now = Head;
	for(int i=0;i<Size;++i)
	{
		std::cout <<now->data << std::endl;
		now = now->Next;
	}
}

template<typename T>
void List<T>::clear()
{
	while(Size)
	{
		pop_front();
		--Size;
	}
}
template<typename T>
List<T>::~List()
{
	clear();
};