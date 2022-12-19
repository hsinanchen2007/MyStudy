这里给出单链表和双链表的设计。
- 单链表
```c
typedef struct node_obj{
    int val;
    struct node_obj* next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj=malloc(sizeof(MyLinkedList));
    obj->next=0;
    obj->val=-1;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index<0) return -1;
    MyLinkedList* tmp=obj->next;
    while(tmp->next!=0&&index){
        tmp=tmp->next;
        index--;
    } 
    if(tmp!=0&&index==0) return tmp->val;
    else return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* head=malloc(sizeof(MyLinkedList));
    head->val=val;
    head->next=obj->next;
    obj->next=head;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* tail=malloc(sizeof(MyLinkedList));
    tail->val=val;
    tail->next=NULL;
    MyLinkedList* tmp=obj;
    while(tmp->next!=0) tmp=tmp->next;
    tmp->next=tail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index>=0){
        MyLinkedList* tmp=obj;
        while(tmp->next!=0&&index){
            tmp=tmp->next;
            index--;
        }
        if(index==0){
            MyLinkedList* node=malloc(sizeof(MyLinkedList));
            node->val=val;
            node->next=tmp->next;
            tmp->next=node;
        }
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index>=0){
        MyLinkedList* tmp=obj;
        MyLinkedList* del;
        while(tmp->next!=0&&index){
            tmp=tmp->next;
            index--;
        }
        if(index==0&&tmp->next!=0){
            del=tmp->next;
            tmp->next=del->next;
            free(del);
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* tmp=obj;
    while(obj!=0){
        tmp=obj;
        obj=tmp->next;
        free(tmp);
    }
}
```
- 双链表
```c
typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj=malloc(sizeof(MyLinkedList));
    obj->val=-1;
    obj->next=0;
    obj->prev=0;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj->next==0) return -1;
    obj=obj->next;
    while(obj->next!=0&&index){
        obj=obj->next;
        index--;
    }
    if(index==0) return obj->val;
    else return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* head=malloc(sizeof(MyLinkedList));
    head->val=val;
    head->next=obj->next;
    head->prev=obj;
    if(head->next!=0) head->next->prev=head;
    obj->next=head;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* tail=malloc(sizeof(MyLinkedList));
    tail->val=val;
    tail->next=0;
    while(obj->next!=0) obj=obj->next;
    obj->next=tail;
    tail->prev=obj;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index>=0){
        while(obj->next!=0&&index){
            obj=obj->next;
            index--;
        }
        if(index==0){
            MyLinkedList* node=malloc(sizeof(MyLinkedList));
            node->val=val;
            node->next=obj->next;
            node->prev=obj;
            obj->next=node;
            if(node->next!=0) node->next->prev=node;
        }
    } 
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index>=0){
        index++;
        while(obj->next!=0&&index){
            obj=obj->next;
            index--;
        }
        if(index==0){
            obj->prev->next=obj->next;
            if(obj->next!=0) obj->next->prev=obj->prev;
            free(obj);
        }
    } 
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* tmp;
    while(obj!=0){
        tmp=obj;
        obj=obj->next;
        free(tmp);
    }
}
```