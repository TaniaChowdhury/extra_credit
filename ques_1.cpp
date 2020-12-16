/*
student name : Tania Chowdhury
Course name : CSCI 313
Professor name : Matthew Fried

EXTRA CREDIT
*/


#include<iostream>
using namespace std;
template <typename T>
class TernaryTreeNode
{
public:
    T data;
    TernaryTreeNode<T>* firstChild;//First child
    TernaryTreeNode<T>* secondChild;//Second child
    TernaryTreeNode<T>* thirdChild;//Third Child
    //Constructor
    TernaryTreeNode(T data)
    {
        this->data=data;
        firstChild=NULL;
        secondChild=NULL;
        thirdChild=NULL;
    }
    //Destructor
    ~TernaryTreeNode(){
        delete firstChild;
        delete secondChild;
        delete thirdChild;
    }
};
void print(TernaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    if(root->firstChild)
    {
        cout<<root->firstChild->data<<" ";
    }
    if(root->secondChild)
    {
        cout<<root->secondChild->data<<" ";
    }
    if(root->thirdChild)
    {
        cout<<root->thirdChild->data<<" ";
    }
    cout<<endl;
    print(root->firstChild);
    print(root->secondChild);
    print(root->thirdChild);
}
int main()
{
    TernaryTreeNode<int>*root=new TernaryTreeNode<int>(1);//Creating the root Node
    TernaryTreeNode<int>*node1=new TernaryTreeNode<int>(2);//Creating the child1 Node
    TernaryTreeNode<int>*node2=new TernaryTreeNode<int>(3);//Creating the child2 Node
    TernaryTreeNode<int>*node3=new TernaryTreeNode<int>(4);//Creating the child3 Node
    root->firstChild=node1;
    root->secondChild=node2;
    root->thirdChild=node3;
    print(root);
    delete(root);
}