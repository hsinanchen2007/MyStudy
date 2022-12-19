### 代码

```c
typedef struct linklist{
    
    int data;
    struct linklist *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    
    MyLinkedList *pHead = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(pHead == NULL){

        return;
    }
    pHead->next = NULL;

    return pHead;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {

    int i = 0;
    MyLinkedList *p = obj->next;
    while(p != NULL && i <index){

        p = p->next;
        i++;
    }

    if(p == NULL || i > index){

        return -1;
    }

    i = p->data;
    return i;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  
    MyLinkedList *p = obj;
    MyLinkedList *node = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    node->data = val;
    node->next = p->next;
    p->next = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  
    MyLinkedList *p = obj;
    MyLinkedList *node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->data = val;

    while(p->next != NULL){

        p = p->next;
    }

    p->next = node;
    node->next = NULL;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  
    int i = 0;
    MyLinkedList *p = obj;
    MyLinkedList *pNew = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    pNew->data = val;

    while((p->next != NULL) && i < index){

        p = p->next;
        i++;
    }
    pNew->next = p->next;
    p->next = pNew;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    int i = 0;
    MyLinkedList *p = obj;
    while((p->next != NULL) && i < index){

        p = p->next;
        i++;
    }

    if(p->next == NULL || i < -1){
        
        return;
    }

    MyLinkedList *delete = p->next;

    p->next = delete->next;
    free(delete);
    
}

void myLinkedListFree(MyLinkedList* obj) {
    
    MyLinkedList *p;
    while(obj){

        p = obj->next;
        free(obj);
        obj = p;
    }
}
```