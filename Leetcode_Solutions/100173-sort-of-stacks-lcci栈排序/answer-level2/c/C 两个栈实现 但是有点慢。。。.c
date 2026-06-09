```
#define MAX_LEN 5000

typedef struct {
  int rankBuf[MAX_LEN];
  int tempBuf[MAX_LEN];
  int *rankTop;
  int *tempTop;
} SortedStack;

SortedStack* sortedStackCreate() 
{
  SortedStack *obj = malloc(sizeof(SortedStack));
  obj->rankTop = obj->rankBuf;
  obj->tempTop = obj->tempBuf;

  return obj;
}

void push(int **top, int val)
{
  *(*top)++ = val;
}

bool empty(int *top, int *buf)
{
  return top == buf;
}

int pop(int **top)
{
  return *(--(*top));
}

int peek(int *top)
{
  return *(top - 1);
}

void sortedStackPush(SortedStack* obj, int val) 
{
  // reset tempBuf
  obj->tempTop = obj->tempBuf;

  while(!empty(obj->rankTop, obj->rankBuf) && val > peek(obj->rankTop))
    push(&(obj->tempTop), pop(&(obj->rankTop)));

  push(&(obj->rankTop), val);

  while(!empty(obj->tempTop, obj->tempBuf))
    push(&(obj->rankTop), pop(&(obj->tempTop)));
}

void sortedStackPop(SortedStack* obj) 
{
  if(!empty(obj->rankTop, obj->rankBuf))
    (void)pop(&(obj->rankTop));
}

int sortedStackPeek(SortedStack* obj) 
{
  if(!empty(obj->rankTop, obj->rankBuf))  return peek(obj->rankTop);
  else                                    return -1;
}

bool sortedStackIsEmpty(SortedStack* obj) 
{
  return empty(obj->rankTop, obj->rankBuf);
}

void sortedStackFree(SortedStack* obj) {
  free(obj);
}

```
