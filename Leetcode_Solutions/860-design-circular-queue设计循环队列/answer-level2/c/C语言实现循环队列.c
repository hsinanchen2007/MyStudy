```c
typedef struct {
    int maxSize;
    int size;
    int* queue;
    int head;
    int tail;
    
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* mcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    mcq->maxSize = k;
    mcq->size = 0;
    mcq->queue = (int*)malloc(k * sizeof(int));
    mcq->head = -1;
    mcq->tail = -1;
    return mcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->maxSize) {
        return false;
    }
    
    if (obj->size == 0) {
        obj->head = obj->tail = 0;
        obj->queue[obj->tail] = value;
    }
    else {
        obj->queue[obj->tail = (obj->tail + 1) % obj->maxSize] = value;
    }
    obj->size++;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return false;
    }
    obj->size--;
    if (obj->size == 0) {
        obj->head = obj->tail = 0;
    }
    else {
        obj->head  = (obj->head + 1) % obj->maxSize;
    }
    
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->queue[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->queue[obj->tail];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return true;
    }
    return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->size == obj->maxSize) {
        return true;
    }
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
```
