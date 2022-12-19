队列是先进先出，在每次添加元素后将该数添加到队头即可
```
typedef struct {
    int* queue;
    int rear;
    int front;
} MyStack;
/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack* obj=(MyStack*)calloc(1,sizeof(MyStack));
    obj->queue=(int*)calloc(100,sizeof(int));
    obj->rear=0;
    obj->front=0;
    return obj;
}
/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(obj->rear==0)
        obj->queue[obj->rear++]=x;
    else
    {
        for(int i=obj->rear-1;i>=obj->front;i--)
            obj->queue[i+1]=obj->queue[i];
        obj->queue[obj->front]=x;
        obj->rear++;
        
    }
}
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(obj->rear==obj->front)
        return -1;
    return obj->queue[obj->front++];
}
/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue[obj->front];
}
/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->rear==obj->front)
        return true;
    return false;
}
void myStackFree(MyStack* obj) {
    free(obj->queue);
    obj->queue=NULL;
    free(obj);
    obj=NULL;
}

```
同类题目，232题，栈实现队列[https://leetcode-cn.com/problems/implement-queue-using-stacks/]()
