#include "Node.h"

Node::Node(char val, int freq)
{
	this->value = val;
	this->freq = freq;
	this->left = nullptr;
	this->right = nullptr;
}

char Node::getValue()
{
	return this->value;
}

int Node::getFrequency()
{
	return this->freq;
}

//bool Node::compare(Node* l, Node* r)
//{
//	return (l->getFrequency() > r->getFrequency());
//}
