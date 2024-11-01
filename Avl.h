//
// Created by Wendy on 31/10/2024.
//

#ifndef AVL_H
#define AVL_H

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value);

};


class Avl {
public:
    Node* root;

    Avl();

    Node* insert(Node* node, int value);
    Node* search(Node* node, int value);
    Node* remove(Node* node, int value);
    void InOrderTraversal(Node* node);
    void  PreOrderTraversal(Node* node);
    void PostOrderTraversal(Node* node);
    int height(Node* node);
    int getBalance(Node* node);

private:
    Node* minValueNode(Node* node);
    Node* rightRotate(Node*  y);
    Node* leftRotate(Node*  x);




};



#endif //AVL_H
