```
typedef struct Stack{
    int data;
    struct Stack* next;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* node = (MyStack*)malloc(sizeof(MyStack));
    node -> next = NULL;
    return node;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    MyStack* node = (MyStack*)malloc(sizeof(MyStack));
    node -> data = x;
    node -> next = obj -> next;
    obj -> next = node;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int data = obj -> next ->data;
    MyStack* p = obj -> next;
    obj -> next= obj -> next -> next;
    free(p);
    return data;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj -> next ->data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj -> next == NULL){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    while(obj -> next != NULL){
        MyStack* p = obj -> next;
        obj -> next = obj -> next -> next;
        free(p);
    }
}
```
