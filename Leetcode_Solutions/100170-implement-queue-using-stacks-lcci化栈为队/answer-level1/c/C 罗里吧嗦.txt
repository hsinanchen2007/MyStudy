```
#define MAX_LEN 1000

typedef struct {
  int stackBuf[2][MAX_LEN];
  int *top[2];
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() 
{
  MyQueue *queue = malloc(sizeof(MyQueue));
  (queue->top)[0] = (queue->stackBuf)[0];
  (queue->top)[1] = (queue->stackBuf)[1];

  return queue;
}

void push(int **top, int x)
{
  *(*top)++ = x;
}

bool empty(int *buf, int *top)
{
  return buf == top;
}

int pop(int **top)
{
  return *(--(*top));
}

int peek(int *top)
{
  return *(top - 1);
}

void reverseCopy(MyQueue* obj, int fromIndex, int desIndex)
{
  // assert(fromIndex != desIndex);
  // assert(fromIndex <= 1);
  // assert(desIndex <= 1);

  int *curTop = (obj->top)[fromIndex];

  // reset stack 2
  (obj->top)[desIndex] = (obj->stackBuf)[desIndex];

  // push data from stack1 to stack2
  while(--curTop >= (obj->stackBuf)[fromIndex])
    push(obj->top + desIndex, *curTop);
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) 
{
  push(obj->top, x);
  reverseCopy(obj, 0, 1);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) 
{
  int ret = pop(obj->top + 1);
  reverseCopy(obj, 1, 0);
  return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) 
{
  return peek((obj->top)[1]);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) 
{
  return empty((obj->stackBuf)[1], (obj->top)[1]);
}

void myQueueFree(MyQueue* obj) 
{
  free(obj);
}

```
