### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int in_stack[100];
    int out_stack[100];
    int in_idx;
    int out_idx;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    return calloc(1,sizeof(MyQueue));
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->in_stack[obj->in_idx++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->out_idx == 0) {
        while(obj->in_idx > 0) {
            obj->out_stack[obj->out_idx++] = obj->in_stack[--obj->in_idx];
        }
    }
    assert(obj->out_idx > 0);
    return obj->out_stack[--obj->out_idx];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->out_idx == 0) {
        while(obj->in_idx > 0) {
            obj->out_stack[obj->out_idx++] = obj->in_stack[--obj->in_idx];
        }
    }
    assert(obj->out_idx > 0);
    return obj->out_stack[obj->out_idx-1];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->in_idx == 0 && obj->out_idx == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
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