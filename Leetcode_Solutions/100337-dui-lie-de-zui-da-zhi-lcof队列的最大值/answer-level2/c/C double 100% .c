
辅助双向队列 写起来真费劲

```
#define MAX_LEN 10000

typedef struct {
  int valueBuf[MAX_LEN];
  int *front;
  int *back;  
} Queue;

void initQueue(Queue *queue)
{
  queue->front = queue->valueBuf;
  queue->back = queue->front;
}

void push_back(Queue *queue, int value)
{
  if(queue->back == queue->valueBuf + MAX_LEN)
    queue->back = queue->valueBuf;
  
  *(queue->back)++ = value;
}

void push_front(Queue *queue, int value)
{
  if(queue->front == queue->valueBuf)
    queue->front = queue->valueBuf + MAX_LEN;
  
  *(--(queue->front)) = value;
}

bool empty(Queue *queue)
{
  return queue->front == queue->back;
}

int pop_front(Queue *queue)
{
  int ret = -1;

  if(!empty(queue))
  {
    ret = *(queue->front)++;

    if(queue->front == queue->valueBuf + MAX_LEN)
      queue->front = queue->valueBuf;
  }

  return ret;
}

int pop_back(Queue *queue)
{
  int ret = -1;

  if(!empty(queue))
  {
    if(queue->back == queue->valueBuf)
      queue->back = queue->valueBuf + MAX_LEN;

    ret = *(--(queue->back));
  }
  
  return ret;
}

int peek_front(Queue *queue)
{
  if(empty(queue))  return -1;
  else              return *(queue->front);
}

int peek_back(Queue *queue)
{
  if(empty(queue)) return -1;

  int ret = pop_back(queue);
  push_back(queue, ret);
  return ret;
}

typedef struct {
  Queue *valueQ;
  Queue *maxQ;
} MaxQueue;

MaxQueue* maxQueueCreate() 
{
  MaxQueue *obj = malloc(sizeof(MaxQueue));
  obj->valueQ = malloc(sizeof(Queue));
  obj->maxQ = malloc(sizeof(Queue));

  initQueue(obj->valueQ);
  initQueue(obj->maxQ);

  return obj;
}

int maxQueueMax_value(MaxQueue* obj) 
{
  return peek_front(obj->maxQ);
}

void maxQueuePush_back(MaxQueue* obj, int value) 
{
  push_back(obj->valueQ, value);

  while(!empty(obj->maxQ) && peek_back(obj->maxQ) < value)
    (void)pop_back(obj->maxQ);

  push_back(obj->maxQ, value);
}

int maxQueuePop_front(MaxQueue* obj) 
{
  int ret = pop_front(obj->valueQ);

  if(!empty(obj->maxQ) && peek_front(obj->maxQ) == ret)
    (void)pop_front(obj->maxQ);

  return ret;
}

void maxQueueFree(MaxQueue* obj) 
{
  free(obj->valueQ);
  free(obj->maxQ);
  free(obj);
}

```
