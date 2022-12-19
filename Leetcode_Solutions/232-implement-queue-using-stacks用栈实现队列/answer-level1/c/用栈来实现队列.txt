```
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType stack1[MaxSize];
    ElemType stack2[MaxSize];
    int top1,top2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *obj=(MyQueue *)malloc(sizeof(MyQueue));
    obj->top1=-1;
    obj->top2=-1;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(obj->top1==MaxSize-1){  
        while(obj->top1!=-1){
            obj->stack2[++obj->top2]=obj->stack1[obj->top1--];
        }
    }
    obj->stack1[++obj->top1]=x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->top2==-1) {
        while(obj->top1!=-1){
            obj->stack2[++obj->top2]=obj->stack1[obj->top1--];
        }
    }
    obj->top2--;
    return obj->stack2[obj->top2+1];

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->top2==-1) {
        while(obj->top1!=-1){
            obj->stack2[++obj->top2]=obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2];
  
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->top1==-1&&obj->top2==-1)
    return true;
    return false;

}

void myQueueFree(MyQueue* obj) {
    free(obj);
    obj=NULL;
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
