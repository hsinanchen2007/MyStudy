# 思路：
利用双栈，区分push和pop的情况

# 代码：
```

#define max 100

typedef struct stack{
    int *data1;
    int *data2;
    int top1;
    int top2;
    }
    MyQueue;


/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *newstack = malloc(sizeof(MyQueue));
    newstack->data1 = malloc(sizeof(int) * max);
    newstack->data2 = malloc(sizeof(int) * max);
    newstack->top1  = -1;
    newstack->top2  = -1;
    return newstack;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(obj->top2 < max && obj->top1 < max){
    while(obj->top2 > -1){
        obj->data1[++(obj->top1)] = obj->data2[(obj->top2)--];
    }
    obj->data1[++(obj->top1)] = x;}
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    while(obj->top1 > -1){
        obj->data2[++(obj->top2)] = obj->data1[(obj->top1)--];
    }
    int ans = obj->data2[(obj->top2)--];
    return ans;
    
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
   while(obj->top1 > -1){
        obj->data2[++(obj->top2)] = obj->data1[(obj->top1)--];
    }
    return obj->data2[(obj->top2)];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
  return (obj->top1 == -1 && obj->top2 == -1);
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

