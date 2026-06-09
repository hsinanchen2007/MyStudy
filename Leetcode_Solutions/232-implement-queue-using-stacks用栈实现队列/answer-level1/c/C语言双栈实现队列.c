![Screenshot from 2020-03-30 12-48-17.png](https://pic.leetcode-cn.com/d81225eedd5a62b340eaa249db4c7290d95b774e70770917a353faf9c5bf9646-Screenshot%20from%202020-03-30%2012-48-17.png)

```c
#define MAX_SIZE 100
typedef struct
{
    int top1;
    int top2;
    int stack1[MAX_SIZE];
    int stack2[MAX_SIZE];
} MyQueue;

/** Initialize your data structure here. */

MyQueue *myQueueCreate()
{
    MyQueue *myQueue = (MyQueue *)malloc(sizeof(MyQueue));
    myQueue->top1 = -1;
    myQueue->top2 = -1;
    return myQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x)
{
    //栈1不满：入栈
    if (obj->top1 < MAX_SIZE - 1)
        obj->stack1[++(obj->top1)] = x;
    //栈1满，栈2空：将栈1元素全部入栈2后入栈1
    else if (obj->top1 >= MAX_SIZE - 1 && obj->top2 == -1)
    {
        while (obj->top1 != -1)
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        obj->stack1[++(obj->top1)] = x;
    }
    //否则，无法入队
    else
        return;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj)
{
    //栈2不空，出栈
    if (obj->top2 != -1)
        return obj->stack2[(obj->top2)--];
    //栈2空，将栈1元素全部入栈2，再从栈2出栈
    else
    {
        while (obj->top1 != -1)
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        return obj->stack2[(obj->top2)--];
    }
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj)
{
    //栈2不空，取栈2栈顶元素
    if (obj->top2 != -1)
        return obj->stack2[(obj->top2)];
    //栈2空，取栈1元素
    else
        return obj->stack1[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj)
{
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}
```
