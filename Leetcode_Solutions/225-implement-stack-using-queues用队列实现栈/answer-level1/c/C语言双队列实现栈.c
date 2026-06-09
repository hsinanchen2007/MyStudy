### 解题思路

使用两个队列，其中一个存储，另一个作为中转。

### 代码

```c
typedef struct {
    int *arr;
    int head;
    int tail;
    int size;
}Queue;

Queue *initQueue(int size){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * size);
    queue->head = -1;
    queue->tail = -1;
    queue->size = size;
    return queue;
}
void enQueue(Queue *queue,int value){
    if(queue->head==-1){
      queue->head=0;
    }
    queue->tail=(queue->tail + 1) % queue->size;
    queue->arr[queue->tail] = value;
}
int deQueue(Queue *queue){
    int value = queue->arr[queue->head];
    if(queue->head == queue->tail){
        queue->tail = -1;
        queue->head = -1;
        return value;
    }
    queue->head = (queue->head + 1) % queue->size;
    return value;
}
int queueIsEmpty(Queue *queue){
    return queue->head == -1;
}

typedef struct {
    Queue *queue1;
    Queue *queue2;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack *stack=(MyStack *)malloc(sizeof(MyStack));
    stack->queue1 = initQueue(1024);
    stack->queue2 = initQueue(1024);
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
  if(!queueIsEmpty(obj->queue1)){
    enQueue(obj->queue1,x);
  }else{
    enQueue(obj->queue2,x);
  }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(queueIsEmpty(obj->queue1)){
        while(obj->queue2->head != obj->queue2->tail){
            enQueue(obj->queue1, deQueue(obj->queue2));
        }
        return deQueue(obj->queue2);
    }
    while(obj->queue1->head != obj->queue1->tail){
        enQueue(obj->queue2, deQueue(obj->queue1));
    }
    return  deQueue(obj->queue1);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(queueIsEmpty(obj->queue1)){
        return obj->queue2->arr[obj->queue2->tail];
    }
    return obj->queue1->arr[obj->queue1->tail];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->queue1->head == -1 && obj->queue2->head == -1){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1->arr);
    free(obj->queue1);
    free(obj->queue2->arr);
    free(obj->queue2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```