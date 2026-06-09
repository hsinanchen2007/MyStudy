### 解题思路


### 代码

```c

typedef struct Node{
    int val;
    struct Node *next;
}MyLinkedList ;


/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {//创建一个头节点
    MyLinkedList *head=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->next=NULL;
    head->val=-1;   
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p=obj->next;
    while(p&&index)
    {
        index--;
        p=p->next;
    }
    if(!p)
    return -1;
    return p->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *new_first=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    new_first->val=val;
    new_first->next=obj->next;
    obj->next=new_first;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *new_tail=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    new_tail->val=val;
    while(obj->next)
    {
        obj=obj->next;
    }
    new_tail->next=NULL;
    obj->next=new_tail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    //index--;
    while(index&&obj)
    {
        index--;
        obj=obj->next;
    }
    if(!obj)
    return ;
    MyLinkedList *new_node=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    new_node->val=val;
    new_node->next=obj->next;
    obj->next=new_node;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  //index--;
  while(index&&obj->next)
  {
      index--;
      obj=obj->next;
  }
  if(!obj->next)
  return;
  MyLinkedList *q=obj->next;
  obj->next=q->next;
  free(q);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *p=obj;
    while(p)
    {
        obj=obj->next;
        free(p);
        p=obj;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
```

```

typedef struct  Node{
    struct Node *next;
    struct Node* pre;
    int val;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->val=-1;
    head->next=NULL;
    head->pre=NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
  obj=obj->next;
  while(index&&obj)
  {
      index--;
      obj=obj->next;
  }
  if(!obj)
  return -1;
  return obj->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  MyLinkedList *new_first=(MyLinkedList *)malloc(sizeof(MyLinkedList));
  new_first->val=val;
  new_first->next=obj->next;
  obj->next=new_first;
  new_first->pre=obj;
  if(!new_first->next)//旧结点不存在
        return ;
  new_first->next->pre=new_first;
  
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  while(obj->next)
  obj=obj->next;
  MyLinkedList *new_tail=(MyLinkedList*)malloc(sizeof(MyLinkedList));
  new_tail->val=val;
  obj->next=new_tail;
  new_tail->pre=obj;
  new_tail->next=NULL;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  while(obj&&index)
  {
      index--;
      obj=obj->next;
  }
  if(!obj)
  return;
  MyLinkedList *new_node=(MyLinkedList *)malloc(sizeof(MyLinkedList));
  new_node->val=val;
  new_node->next=obj->next;
  obj->next=new_node;
  new_node->pre=obj;
  if(new_node->next)
    new_node->next->pre=new_node;

}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  MyLinkedList *q;
  while(index&&obj)
  {
      index--;
      obj=obj->next;
  }
  if(!obj||!obj->next)
    return ;
    q=obj->next;
    obj->next=q->next;
    if(q->next)
    q->next->pre=obj;
    printf("the q is :%d\n",q->val);
    free(q);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList  *p=obj;
    while(obj)
    {
        obj=obj->next;
        free(p);
        p=obj;
    }
    p=NULL;
    obj=NULL;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
```
