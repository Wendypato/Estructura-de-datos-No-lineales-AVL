#include <iostream>
#include "Avl.h"

using namespace std;

int main()
{
    Avl tree;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);
    //ejemplo de busquda
    Node* searchResult = tree.search(tree.root,20);
    if (searchResult) {
        cout << "Valor 20 encontrado en el arbol." << endl;
    } else {
        cout << "Valor 20 no encontrado en el arbol." << endl;
    }
    //Ejemplo de eliminacion
    tree.root = tree.remove(tree.root, 10);
    cout<<"Eliminado el nodo con valor 10. "<<endl;

    cout<<"In order traversal: ";
    tree.InOrderTraversal(tree.root);
    cout << endl;

    cout<<"Pre order traversal: ";
    tree.PreOrderTraversal(tree.root);
    cout << endl;

    cout<<"Post order traversal: ";
    tree.PostOrderTraversal(tree.root);
    cout << endl;


    //Verificacion de balanceo en nodos clave
    cout<<"Factor de balance de la raiz: "<<tree.getBalance(tree.root)<<endl;
    cout<<"Factor de balance del nodo izquierdo de la raiz: ";
    if (tree.root->left) cout<< tree.getBalance(tree.root->left)<<endl;
    else cout<<"No tiene hijo izquierdo"<<endl;

    cout<< "Factor de balance del nodo derecho de la raiz: ";
    if (tree.root->right) cout<<tree.getBalance(tree.root->right)<<endl;
    else cout<< "No tiene hijo derecho"<<endl;

    return 0;
}
