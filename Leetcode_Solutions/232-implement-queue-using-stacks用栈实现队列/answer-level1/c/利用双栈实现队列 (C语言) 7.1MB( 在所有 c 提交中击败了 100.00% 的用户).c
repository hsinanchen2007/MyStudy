
![批注 2019-11-22 164356.png](https://pic.leetcode-cn.com/9c27e4ae580d7b3c81ad6716a78df6b154011ff3ed4731b8d4ef4fcf32f6425a-%E6%89%B9%E6%B3%A8%202019-11-22%20164356.png)


```
#define MAXSIZE 100
//创建栈
struct Stack{
    int Data[MAXSIZE];
    int TOP;
};
typedef struct Stack MyStack;
//队列定义为双栈
typedef struct {
    MyStack S1; //S1为主栈
    MyStack S2; //S2为用来反转的栈
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* TempQueue=(MyQueue*)malloc(sizeof(MyQueue));
    TempQueue->S1.TOP=-1;
    TempQueue->S2.TOP=-1;
    return TempQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    
    if(obj->S1.TOP<MAXSIZE){ //栈是否满
        while(obj->S1.TOP!=-1){
            obj->S2.Data[++(obj->S2.TOP)]=obj->S1.Data[(obj->S1.TOP)--]; //把S1栈中元素压入S2实现反转
        }
        obj->S1.Data[++(obj->S1.TOP)]=x; //把push的元素压入S1栈（此时S1为空栈，因为它的元素已经全部给S2啦）
        while(obj->S2.TOP!=-1){
            obj->S1.Data[++(obj->S1.TOP)]=obj->S2.Data[(obj->S2.TOP)--]; //再把S2栈中的元素全部反转压入S1
        }
    }
    
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->S1.TOP!=-1)
        return obj->S1.Data[(obj->S1.TOP)--];
    return NULL;   
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->S1.TOP!=-1)
        return obj->S1.Data[obj->S1.TOP];
    return NULL; 
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->S1.TOP==-1)
        return true;
    return false;
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
