```
typedef struct Elmt_ {
    int val;
    struct Elmt_ *next;
} Elmt;

typedef struct {
    int size;
    Elmt *top;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *myQueue = (MyQueue *)malloc(sizeof(MyQueue));
    myQueue->top = NULL;
    myQueue->size = 0;
    return myQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    Elmt *element = (Elmt *)malloc(sizeof(Elmt));
    element->val = x;
    if (obj->size == 0) {
        obj->top = element;
        element->next = NULL;
    }
    else {
        element->next = obj->top;
        obj->top = element;
    }
    obj->size++;
    return;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    Elmt *temp, *prev;
    int popValue;

    temp = obj->top;

    if (obj->size == 1) {
        obj->top = NULL;
    }
    else {
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }

    obj->size--;
    popValue = temp->val;
    free(temp);
    return popValue;
    
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    Elmt *temp = obj->top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp->val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj->size == 0) return true;
    else return false;
}

void myQueueFree(MyQueue* obj) {
    int temp;
    while (obj->size != 0) 
        temp = myQueuePop(obj);
    memset(obj, 0, sizeof(MyQueue));
    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
```
