//
// Created by Wendy on 31/10/2024.
//

#include "Avl.h"
#include <algorithm>
#include <iostream>

using namespace std;

Node::Node(int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
    height = 1;
}

Avl::Avl()
{
    root = nullptr;
}

int Avl::height(Node* node)
{
    return node ? node->height : 0;
}

int Avl::getBalance(Node* node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

Node* Avl::rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* Avl::leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2= y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* Avl::insert(Node* node, int value)
{
    if(node==nullptr)
    {
        return new Node(value);
    }
    if(value < node->data)
    {
        node->left = insert(node->left, value);
    }else
    {
        node->right = insert(node->right, value);
    }
    return node;

    node->height = 1 +max(height(node->left), height(node->right));
    int balance = getBalance(node);

    //caso LL
    if(balance < -1 && value >node ->right->data)
    {
        return leftRotate(node);
    }

    // Caso RR
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Caso LR
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso RL
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* Avl::search(Node* node, int value)
{
    if(node==nullptr || node->data == value)
    {
        return node;
    }
    if(value < node->data)
    {
        return search(node->left, value);
    }
    return search(node->right, value);
}

Node* Avl::minValueNode(Node* node)
{
    Node* current = node;
    while(current && current ->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node* Avl::remove(Node* node, int value) {
    if (node == nullptr) return node;

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Balancear el árbol
    if (balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


void Avl::InOrderTraversal(Node* node)
{
    if(node)
    {
        InOrderTraversal(node->left);
        cout<<node->data<<" ";
        InOrderTraversal(node->right);
    }
}

void Avl::PreOrderTraversal(Node* node)
{
    if(node)
    {
        cout<<node->data<<" ";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
    }
}

void Avl::PostOrderTraversal(Node* node)
{
    if(node)
    {
        PostOrderTraversal(node->left);
        PostOrderTraversal(node->right);
        cout<<node->data<<" ";
    }
}