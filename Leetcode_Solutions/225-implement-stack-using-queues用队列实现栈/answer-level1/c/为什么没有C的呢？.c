## 两个固定大小的队列模拟栈
```
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7.2 MB, 在所有 C 提交中击败了81.82%的用户
```
```c
//题目要求  对一个空的栈不会调用 pop 或者 top 操作
#include <stdlib.h>
#define LEN 20
typedef struct queue{
    int *data;
    int head;
    int rear;
    int size;
}Queue;
typedef struct {
    Queue *q1,*q2;
} MyStack;

Queue *initQueue(int k){
    Queue *obj=(Queue *)malloc(sizeof(Queue));
    obj->data=(int *)malloc(k*sizeof(int));
    obj->head=-1;
    obj->rear=-1;
    obj->size=k;
    return obj;
}
void enQueue(Queue *obj,int e){
    //入队的时候，此题不必考虑队列满状态情形
    //队列为空的情形
    if(obj->head==-1){
      obj->head=0;
    }
    //队列一般情形
    obj->rear=(obj->rear+1)%obj->size;
    obj->data[obj->rear]=e;
}
int deQueue(Queue *obj){
    //出队的时候，此题不必考虑队列为空的情形
    int a=obj->data[obj->head];
    //特殊情形，队列中只有一个元素
    if(obj->head==obj->rear){
        obj->rear=-1;
        obj->head=-1;
        return a;
    }
    //队列一般情形
    obj->head=(obj->head+1)%obj->size;
    return a;
}
int isEmpty(Queue *obj){
    return obj->head==-1;
}

/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack *obj=(MyStack *)malloc(sizeof(MyStack));
    obj->q1=initQueue(LEN);
    obj->q2=initQueue(LEN);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
  //只要我找到一个队列为非空，我就向里面添加元素，如果两个都是空的，那随便哪一个都可以
  if(isEmpty(obj->q1)){
    enQueue(obj->q2,x);
  }else{
    enQueue(obj->q1,x);
  }
}

/** Removes the element on top of the stack and returns that element. */
//栈弹出的时候，有且只有一个队列为非空
int myStackPop(MyStack* obj) {
    //q2为非空的时候，q2出列直到q2中只有一个元素
    if(isEmpty(obj->q1)){
        while(obj->q2->head != obj->q2->rear){
            //q2出列的元素，入列q1
            enQueue(obj->q1,deQueue(obj->q2));
        }
        return  deQueue(obj->q2);
    }
    //反之q1非空
    while(obj->q1->head != obj->q1->rear){
        enQueue(obj->q2,deQueue(obj->q1));
    }
    return  deQueue(obj->q1);
}

/** Get the top element. */
//取栈顶元素，有且只有一个队列为非空，我直接取非空队列的尾部即可
int myStackTop(MyStack* obj) {
    if(isEmpty(obj->q1)){
        return obj->q2->data[obj->q2->rear];
    }
    return obj->q1->data[obj->q1->rear];
}

/** Returns whether the stack is empty. */
//当且仅当两个队列都是空的情形
bool myStackEmpty(MyStack* obj) {
    if(obj->q1->head==-1 && obj->q2->head==-1){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    obj->q1->data=NULL;
    free(obj->q1);
    obj->q1=NULL;
    free(obj->q2->data);
    obj->q2->data=NULL;
    free(obj->q2);
    obj->q2=NULL;
    free(obj);
    obj=NULL;
}
```