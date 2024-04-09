#include <stdio.h>
#include <stdlib.h>
//#include <iomanip>
#include "dltypes.h"


void insertNode(int);
void printAllNodesHead(void);
void printAllNodesTail(void);
int  size();
Node * getAt(int);
void insertAt(int, int);

Node *tail = NULL;
Node *head = NULL;

int main(){
  insertNode(10);
  insertNode(0);
  insertNode(1);
  insertNode(56);
  insertNode(98);
  insertNode(100);

  printf("=======Showing elements using Head pointer===========\n");
  printAllNodesHead();

  printf("The size = %d\n", size());
  Node * ele = getAt(5);
  printf("LinkedList[5] = %d\n", ele->data);
  insertAt(0, 4);
  insertAt(2, 16);
  insertAt(5, 12);
 
  printf("=======Showing elements using Head pointer===========\n");
  printAllNodesHead();
  printf("The size = %d\n", size());
  
  ele = getAt(2);
  printf("LinkedList[2] = %d\n", ele->data);

  return 0;
}


int size(){

  Node * temp = head;
  int count=0;
  while (temp){
    temp = temp->next;
    count++;
  }
  return count;
}

Node * getAt(int index){
  Node * temp = head;
  int count = size();
  if (index < 0 || index > count -1 || !temp){
    printf("Exception: Index at %d is invalid or invalid pointer\n", index);
    return NULL;
  }

  for (int i=0; i < index; i++){
    temp = temp->next;
  }

  return temp;

}

void insertAt(int index, int data){
  Node * temp = head;
  Node * currNode = getAt(index);
  Node * prevNode = currNode->prev;
  // creating new node 
  Node * n = (Node *)malloc(sizeof(Node));
  n->data = data;

  if (prevNode == NULL){
    // insert at the begining
    n->prev = NULL;
    n->next = currNode;
    currNode->prev = n;
    // change head pointer to point at the new BEGINING of the list.
    head = n;
  }
  else if (currNode == tail){
    // insert at the end of the list
    currNode->next = n;
    n->prev = currNode;
    n->next = NULL;
    // updates the tail pointer to point at the new END.
    tail = n;

  }
  else{
    n->next = currNode;
    n->prev = prevNode;

    prevNode->next = n;
    currNode->prev = n;
  }
}


void printAllNodesHead(){
  Node * temp = head;

  if (temp == NULL)
    printf("Empty list\n");
  
  while (temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
void printAllNodesTail(){
  Node * temp = tail;

  if (temp == NULL)
    printf("Empty list\n");
  
  while (temp != NULL){
    printf("%d ", temp->data);
    temp = temp->prev;;
  }
  printf("\n");
}

void insertNode(int data){
    //Node * previous = NULL;
    //Node * temp = head;
    // first node in the list
    Node * n = (Node *)malloc(sizeof(Node));
    n->data = data;

    if (head == NULL){
        // first node
        n->prev = NULL;
        n->next = NULL;
        head = n;
        tail = n;
    }
    else{
        tail->next = n;
        n->prev = tail;
        tail = n;
        tail->next = NULL;

    }
}

