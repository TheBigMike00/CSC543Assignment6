#include<stdio.h>
#include <queue>
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

//compare frequency to two nodes
struct compare 
{
    bool operator()(Node* l, Node* r)
    {
        return (l->getFrequency() > r->getFrequency());
    }
};

// Prints huffman codes recursively starting with root node and empty string
void display(Node* root, string str)
{

    if (!root)
        return;

    if (root->getValue() != '!')
        cout<< root->getValue() << ": " << str << "\n";

    display(root->left, str + "0");
    display(root->right, str + "1");
}

//Funcion that builds the tree
void Huffman(char data[], int freq[], int size)
{
    Node* left, * right, * top;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    while (minHeap.size() != 1) 
    {
        // Extract the two minimum frequency nodes from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        //new node without a character value
        top = new Node('!', left->getFrequency() + right->getFrequency());

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    //display final result
    display(minHeap.top(), "");
}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    Huffman(arr, freq, size);
}