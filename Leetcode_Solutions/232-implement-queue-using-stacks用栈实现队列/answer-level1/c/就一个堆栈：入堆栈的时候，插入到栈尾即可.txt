```
typedef struct Queue{
    int data;
    struct Queue * next;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue * obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj -> next = NULL;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    MyQueue * q = (MyQueue*)malloc(sizeof(MyQueue));
    q -> data = x;
    while(obj -> next != NULL){
        obj = obj -> next;
    }
    q -> next = obj -> next;
    obj -> next = q;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int data = obj -> next -> data;
    MyQueue* tmp = obj -> next;
    obj -> next = obj -> next -> next;
    free(tmp);
    return data;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int data = obj -> next -> data;
    return data;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj ->next == NULL){
        return true;
    }
    return false;
}

void myQueueFree(MyQueue* obj) {
    while(obj -> next != NULL){
        MyQueue* tmp = obj ->next;
        obj ->next = obj -> next ->next;
        free(tmp);
    }
}
```
