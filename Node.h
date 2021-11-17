#pragma once
class Node
{
private:
	char value;
	int freq;

public:
	Node(char val, int freq);
	Node* left;
	Node* right;
	char getValue();
	int getFrequency();
	//bool compare(Node* l, Node* r); have to to in driver to make priority queue work
};