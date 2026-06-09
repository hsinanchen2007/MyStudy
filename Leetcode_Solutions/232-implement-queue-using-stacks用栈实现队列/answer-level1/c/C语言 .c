### 解题思路
使用两个栈
一个存储顺序的数据
另一个用来反转数据

### 代码

```c
#define MAXSIZE 100
typedef struct {
    int top;
    int data[MAXSIZE];
} MyStack;
typedef struct {
    MyStack S1;
    MyStack S2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* Q = (MyQueue*)malloc(sizeof(MyQueue));
    Q->S1.top = -1;
    Q->S2.top = -1;
    return Q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
     if(obj->S1.top<MAXSIZE-1){
        while(obj->S1.top!=-1){
            obj->S2.data[++(obj->S2.top)] = obj->S1.data[(obj->S1.top)--];
        }
        obj->S1.data[++(obj->S1.top)] = x;
        while(obj->S2.top!=-1){
            obj->S1.data[++(obj->S1.top)] = obj->S2.data[(obj->S2.top)--];
        }
     }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->S1.top!=-1){
        return obj->S1.data[(obj->S1.top)--];
    }
    return NULL;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->S1.top!=-1){
        return obj->S1.data[obj->S1.top];
    }
    return NULL;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
   return obj->S1.top==-1;
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