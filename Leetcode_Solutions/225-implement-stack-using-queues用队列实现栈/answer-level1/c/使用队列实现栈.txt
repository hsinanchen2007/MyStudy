```
typedef struct Elmt_ {
    int val;
    struct Elmt_ *next;
} Elmt; // 节点元素

typedef struct {
    int size;
    Elmt *head;
    Elmt *tail;
} MyStack; // 使用队列实现的栈，队列由单链表实现

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *mySatck = (MyStack *)malloc(sizeof(MyStack));
    mySatck->head = NULL;
    mySatck->tail = NULL;
    mySatck->size = 0;
    return mySatck;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    Elmt *element = (Elmt *)malloc(sizeof(Elmt));
    element->val = x;
    element->next = NULL;

    if (obj->size == 0) {
        obj->head = element; 
        obj->tail = element;   
    }
    else {
        obj->tail->next = element;
        obj->tail = element;
    }
    obj->size++;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int popValue;
    Elmt *temp, *prev;

    if (obj->size == 1) {
        temp = obj->head;
        obj->head = obj->tail = NULL;  
    }
    else {
        temp = obj->head;
        while (temp != obj->tail) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        obj->tail = prev;
    }

    popValue = temp->val;
    free(temp);
    obj->size--; 

    return popValue;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->tail->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->size == 0)
        return true;
    else 
        return false;
}

void myStackFree(MyStack* obj) {
    while(obj->size != 0)
        myStackPop(obj);
    return;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```
