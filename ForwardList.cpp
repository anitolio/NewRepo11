#include <iostream>
#include "ForwardList.h"

void ForwardList::clear() 
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
	}
	head = nullptr;
	tail = nullptr;
}

ForwardList::ForwardList() : head(nullptr), tail(nullptr) {}

ForwardList::ForwardList(const ForwardList& other) : head(nullptr), tail(nullptr)
{
	std::cout << "copy\n";
	Node* current = other.head;
	while (current != nullptr) {
		push_back(current->data);
		current = current->next;
	}
}

ForwardList& ForwardList::operator=(const ForwardList& other)
{
	if (this == &other) {
		return *this;
	}

	clear(); 

	Node* current = other.head;
	while (current != nullptr) {
		push_back(current->data);
		current = current->next;
	}

	return *this;
}

void ForwardList::push_back(int value)
{
	Node* new_node = new Node(value);
	if (tail) {
		tail->next = new_node;
	}
	else {
		head = new_node;
	}
	tail = new_node;
}

void ForwardList::pop_front()
{
	if (head) {
		Node* temp = head->next;
		delete head;
		head = temp;
		if (!head) {
			tail = nullptr;
		}
	}
}

void ForwardList::pop_back()
{
	if (!head) return;

	if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else {
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		delete tail;
		tail = current;
		tail->next = nullptr;
	}
}

const Node* ForwardList::find(int value)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == value) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void ForwardList::print()
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->data << ' ';
		current = current->next;
	}
	std::cout << std::endl;
}

ForwardList::~ForwardList()
{
	clear();
}