### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct b{
    int val;
    struct b* next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* pre=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    pre->next=NULL;
    return pre;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index<0) return -1;
     index++;
    while(index--){
        obj=obj->next;
        if(obj==NULL) return -1;
    }
    return obj->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* newhead=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    newhead->val=val;
    newhead->next=obj->next;
    obj->next=newhead;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
   while(obj->next) obj=obj->next;
   MyLinkedList* tail=(MyLinkedList*)malloc(sizeof(MyLinkedList));
   tail->val=val;
   tail->next=NULL;
   obj->next=tail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  while(index--){
      obj=obj->next;
  }
  MyLinkedList* c=(MyLinkedList*)malloc(sizeof(MyLinkedList));
  c->val=val;
  c->next=obj->next;
  obj->next=c;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    // index--;
    while(index--){
        obj=obj->next;
        if(obj==NULL||obj->next==NULL) return;
    }
   MyLinkedList* a=obj->next;
   obj->next=a->next;
   free(a);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* temp;
    while(obj){
        temp=obj->next;
        free(obj);
        obj=temp;
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