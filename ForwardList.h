#pragma once

class Node
{
public:
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(int value)
		: data(value), next(nullptr)
	{}
};


class ForwardList
{
private:
	Node* head;
	Node* tail;
	void clear();
public:
	ForwardList();
	ForwardList(const ForwardList& other);
	ForwardList& operator=(const ForwardList& other) = delete;
	~ForwardList();


	void push_back(int value);
	void pop_front();
	void pop_back();
	const Node* find(int value);
	void print();
};
	