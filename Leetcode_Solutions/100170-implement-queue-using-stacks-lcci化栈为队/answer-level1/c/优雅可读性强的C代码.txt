思路：队列是一端进行删除（即出队），另一端进行插入（即入队）的数据结构。
题目要求2个栈空间，那么我们使一个限制为只能进行pop操作，一个只能进行push操作，模仿队列的入队和出队操作。
pop栈我们命名为frontStack，push栈我们命名为rearStack，接下来的代码实现中有详细的注释。

```
#define MAXSIZE 30
#define OK 1
#define ERR 0

typedef struct Stack
{
    int top;
    int data[MAXSIZE];
}Stack, * StackPtr;

typedef struct {
    Stack* rearStack;
    Stack* frontStack; 
} MyQueue, * MyQueuePtr;

bool myQueueEmpty(MyQueue* obj);

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    
    //初始化队列空间
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    if (!obj)
        goto err1;
    memset(obj, 0, sizeof(MyQueue));

    //初始化push栈空间
    obj->rearStack = (Stack*)malloc(sizeof(Stack));
    if (!obj->rearStack)
        goto err2;
    memset(obj->rearStack, 0, sizeof(Stack));
    obj->rearStack->top = -1;

    //初始化pop栈空间
    obj->frontStack = (Stack*)malloc(sizeof(Stack));
    if (!obj->frontStack)
        goto err3;
    memset(obj->frontStack, 0, sizeof(Stack));
    obj->frontStack->top = -1;


    return obj;


    //集中处理malloc失败的情况。
err3:
    if (obj->frontStack)
        free(obj->frontStack);
err2:
    if (obj->rearStack)
        free(obj->rearStack);
err1:
    if (obj)
        free(obj);

    return NULL;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {   
        //判断是否队满
    if (obj->rearStack->top == MAXSIZE - 1)
        return;

    //将pop栈的数据转移到push栈，若没有则直接退出
    while (obj->frontStack->top != -1)
    {
        obj->rearStack->data[++obj->rearStack->top] = obj->frontStack->data[obj->frontStack->top--];
    }
    
    //将数据push
    obj->rearStack->data[++obj->rearStack->top] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    //判断队列是否为空
    if (myQueueEmpty(obj))
        return ERR;
    
    //将push栈的数据转移到pop栈，若没有则直接退出
    while (obj->rearStack->top != -1)
    {
        obj->frontStack->data[++obj->frontStack->top] = obj->rearStack->data[obj->rearStack->top--];
    }

    //pop出去，并返回。
    return obj->frontStack->data[obj->frontStack->top--];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (myQueueEmpty(obj))
        return ERR;

    //判断现在数据在哪个栈空间。
    if (obj->frontStack->top == -1)
    {
        return obj->rearStack->data[0]; //在rear栈中，此时rear指向rear栈的top次，front指向0处
    }
    else
    {
        return obj->frontStack->data[obj->frontStack->top]; //front栈中，直接返回即可
    }
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->frontStack->top == -1 && obj->rearStack->top == -1) ? true : false;
}

//逐一free内存
void myQueueFree(MyQueue* obj) {
    free(obj->frontStack);
    free(obj->rearStack);
    free(obj);
}
```
