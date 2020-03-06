

#include <iostream>
using namespace std;

class Node //clase que genera los nodos para las listas.
{
public:
    int data;
    Node*next;
    Node(int d, Node *n= NULL): data(d), next(n){}

};

class LList //
{
private:
    Node *head;
    Node *tail;
    int length;
public:
    //Constructor
    LList(){head = NULL; tail = NULL;}

    void insertAfter(Node *curNode, int val);
    //if NULL insert at beggining of list
    Node* search(int key)const;
    void removeAfter(Node* curNode);

};

void LList::insertAfter(Node *curNode, int val){
  //if NULL insert at beggining of list
  Node* n=new Node(val);
  if(head == NULL)head = tail = n;
  else if(curNode == NULL){
    n -> next = head;
    head = n;
  }
  else if(curNode == tail){
    curNode -> next = n;
    tail = n;
  }
  else{
    n->next = curNode -> next;
    curNode -> next = n;
  }
  length++;
}


/*int LList::at( int idx) Constructor{
    if(idx < 0 || idx > length)
    {
        cout << "error" << endl;
        exit(1);
    }
}*/


Node* LList :: search(int key)const{
  Node *p = head;
  while( p!=NULL)
  {
    if (p->data == key)
      return p;

    p = p-> next;
  }
  return p;
}

void LList:: removeAfter(Node* curNode){
  Node* t = nullptr;
  if (curNode == NULL)
  {
  t = head;
    head =  head -> next;
    if (head ==NULL)
      tail = NULL;
  }
  else{
    t = curNode -> next;
    curNode -> next = t -> next;
    if( tail==t)tail = curNode;
  }
  delete t;
  length --;
}


int main()
{
  LList L;
  L.insertAfter(NULL, 8);
  L.insertAfter(NULL,15);
  L.insertAfter(NULL,6);
  Node* t = L.search(15);
  L.insertAfter(t,42);
  return 0;
}

