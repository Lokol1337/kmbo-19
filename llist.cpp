#include <iostream>
#include "llist.h"
#include <utility>

using namespace std;


template < typename T>
LList<typename T>::LList()
{
	head = nullptr;
}
template < typename T>
LList < typename T>::~LList()
{
	Node* delNode = nullptr;
	for (delNode = head; head; delNode = head)
	{
		head = head->next;
		delete delNode;
		delNode = nullptr;
	}
}

template < typename T>
T LList< typename T>::operator[](size_t idx) const
{
	Node* bufNode = head;
	for (int i = 0; i < idx; ++i) {
		bufNode = bufNode->next;
	}

	return bufNode->data;
}
template < typename T>
T& LList< typename T>::operator[](size_t idx)
{
	Node* bufNode = head;
	for (int i = 0; i < idx; ++i) {
		bufNode = bufNode->next;
	}

	return bufNode->data;
}

template < typename T>
void LList< typename T>::push_back(T val)
{
	Node* nd = new Node;
	nd->data = val;
	nd->next = NULL;
	if (head == NULL)
		head = nd;
	else
	{
		Node* current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = nd;
	}
}

template < typename T>
void LList< typename T>::push_front(T val)
{
	Node* nd = new Node;

	if (head)
	{
		Node* tmp = head;
		head = nd;
		nd->next = tmp;
		nd->data = val;
	}
	else
	{
		head = nd;
		nd->next = NULL;
		nd->data = val;
	}
}

template < typename T>
void LList< typename T>::pop_back()
{
	if (head == NULL)
		return;
	if (head->next!=NULL)
	{
		Node* tmp = head;
		Node* nd = head;
		while (tmp->next != NULL)
		{
			nd = tmp;
			tmp = tmp->next;
			cout << tmp;
		}
		nd->next = NULL;
		delete tmp;
		tmp = NULL;
	}
	else
	{
		delete head;
		head = NULL;
	}
}

template < typename T>
void LList< typename T>::pop_front()
{
	if (head)
	{
		Node* tmp = head;
		tmp = tmp->next;
		delete head;
		head = tmp;
	}
	else
		cout << "The list is empty!" << endl;
}

template < typename T>
size_t LList< typename T>::size() const {
	int counter = 0;
	Node* nd = head;
	while (nd)
	{
		nd = nd->next;
		counter++;
	}
	return counter;
}


template < typename T>
void LList< typename T>::erase_at(size_t idx)
{
	if (head)
	{
		if (idx != 0)
		{
			int counter = 0;
			Node* tmp = head;
			while (counter <= idx)
			{
				tmp = tmp->next;
				counter++;
			}
			counter = 0;
			Node* nd = head;
			while (counter < idx - 1)
			{
				nd = nd->next;
				counter++;
			}
			nd->next = tmp;
		}
		else
		{
			Node* tmp = head;
			tmp = tmp->next;
			delete head;
			head = tmp;
		}
	}
	else
		cout << "The list is empty!" << endl;
}

template < typename T>
void LList< typename T>::insert_at(size_t idx, T val)
{
	Node* tmp = head;
	int k = 0;
	while (tmp)
	{
		tmp = tmp->next;
		k++;
	}
	if (idx == 0)
	{
		Node* nd = new Node;

		if (head)
		{
			Node* current = head;
			head = nd;
			nd->next = current;
			nd->data = val;
		}
		else
		{
			head = nd;
			nd->next = NULL;
			nd->data = val;
		}
	}
	if (idx == k)
	{
		Node* nd = new Node;
		nd->data = val;
		nd->next = NULL;
		if (head == NULL)
			head = nd;
		else
		{
			Node* current = head;
			while (current->next != NULL)
				current = current->next;
			current->next = nd;
		}
	}
	if (idx != 0 && idx != k)
	{
		Node* nd = head;
		int counter = 0;
		while (counter < idx - 1)
		{
			nd = nd->next;
			counter++;
		}
		Node* current = head;
		counter = 0;
		while (counter < idx)
		{
			current = current->next;
			counter++;
		}
		Node* a = new Node;
		nd->next = a;
		a->next = current;
		a->data = val;
	}

}

template < typename T>
void LList< typename T>::reverse()
{
	Node* tmp = head;
	Node* next = NULL;
	Node* last = NULL;
	while (tmp)
	{
		next = tmp->next;
		tmp->next = last;
		last = tmp;
		tmp = next;
	}
	head = last;
}


template < typename T>
LList< typename T>::LList(const LList& copyLList2)
{
	
	this->head = nullptr;
	Node* currentNode = copyLList2.head;
	while (currentNode)
	{
		this->push_back(currentNode->data);
		currentNode = currentNode->next;
	}
}

template < typename T>
LList< typename T>::LList(LList&& copyLList)
{
	this->head = copyLList.head;
	copyLList.head = nullptr;
}


int main()
{
	/*LList<int> a;
	LList<int> c;
	c.push_back(1);
	c.push_back(2);
	a.push_back(3);
	a.push_back(4);
	LList<int> b(move(a));
	LList<int> d(c);
	cout << d[1] << " " << c[1];*/
}


