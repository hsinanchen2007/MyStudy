### 解题思路
比较栈和队列数据结构的区别
```c
typedef struct {

	int *base;
	int *top;
	int stacksize;

} StackStucture;

typedef struct {

    int *base;
	int front;
	int rear;
} QueueStructure;
```c
栈的 *base一直指向栈底，而队列的front和rear均是变化值，*base只作为存储数据使用
### 代码

```c
#define MAXQSIZE 1000

typedef struct {

    int *base;
	int front;
	int rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {

    MyStack *queue = (MyStack *)malloc(sizeof(MyStack)); //队列的构造
	queue->base = (int *)malloc(sizeof(int) * MAXQSIZE);
	queue->front = queue->rear = 0;
	return queue;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {     //push栈和队列类似

    if ((obj->rear + 1) % MAXQSIZE == obj->front)
		return;

	obj->base[obj->rear] = x;
	obj->rear = (obj->rear + 1) % MAXQSIZE;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {

    int x;
    if (obj->rear == obj->front)
        return -1;

    x = myStackTop(obj);
    obj->rear = (obj->rear - 1) % MAXQSIZE;

    return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {

    return obj->base[obj->rear - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {

    if (obj->rear == obj->front)
        return true;

    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->base);
    free(obj);
}

```