
use a extra int to record the previous min_val

```
#define MAX_LEN 1000

typedef struct {
  int val;
  int preMin;
} Node;

typedef struct {
  Node stackBuf[MAX_LEN];
  Node *top;
  int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate()
{
  MinStack *stack = malloc(sizeof(MinStack));
  stack->top = stack->stackBuf;
  stack->min = INT_MAX;

  return stack;
}

bool empty(MinStack* obj)
{
  return obj->top == obj->stackBuf;
}

bool full(MinStack* obj)
{
  return obj->top - obj->stackBuf == MAX_LEN;
}

void minStackPush(MinStack* obj, int x) 
{
  if(full(obj)) return;

  Node newNode;
  newNode.val = x;
  newNode.preMin = obj->min;

  *(obj->top)++ = newNode;

  if(x < obj->min) obj->min = x;
}

void minStackPop(MinStack* obj) 
{
  if(empty(obj)) return;

  Node node = *(--(obj->top));
  obj->min = node.preMin;
}

int minStackTop(MinStack* obj) 
{
  if(empty(obj)) return -1;
  return (*(obj->top - 1 )).val;
}

int minStackGetMin(MinStack* obj) 
{
  return obj->min;
}

void minStackFree(MinStack* obj) 
{
  free(obj);
}

```
