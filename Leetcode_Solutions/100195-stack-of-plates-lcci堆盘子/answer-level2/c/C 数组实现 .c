
笨办法，初始化阶段一次性分配足够的栈空间。

结果：80% & 100%

```
#define MAX_SET 1000

typedef struct {
  int *stackBuf[MAX_SET];
  int *top[MAX_SET];
  int curSet;
  int cap;
} StackOfPlates;

StackOfPlates* stackOfPlatesCreate(int cap)
{
  if(cap == 0) return NULL;

  StackOfPlates *stacks = malloc(sizeof(StackOfPlates));
  stacks->curSet = 0;
  stacks->cap = cap;

  for(int i = 0; i < MAX_SET; i++)
  {
    (stacks->stackBuf)[i] = malloc(sizeof(int) * cap);
    (stacks->top)[i] = (stacks->stackBuf)[i];
  }

  return stacks;
}

bool full(StackOfPlates* obj)
{
  return (obj->top)[obj->curSet] - (obj->stackBuf)[obj->curSet] == obj->cap;
}

void stackOfPlatesPush(StackOfPlates* obj, int val) {

  if(obj == NULL) return;

  assert(obj->curSet < MAX_SET);

  if(full(obj))
  {
    (obj->curSet)++;
    stackOfPlatesPush(obj, val);
  }
  else
  {
    *((obj->top)[obj->curSet])++ = val;
  }
}

bool empty(StackOfPlates* obj, int index)
{
  return (obj->top)[index] == (obj->stackBuf)[index];
}

int stackOfPlatesPop(StackOfPlates* obj) 
{
  if(obj == NULL) return -1;

  int ret = -1;

  if(!empty(obj, obj->curSet))
  {
    ret = *(--((obj->top)[obj->curSet]));

    while(empty(obj, obj->curSet) && obj->curSet > 0)
      (obj->curSet)--;
  }

  return ret;
}

int stackOfPlatesPopAt(StackOfPlates* obj, int index) 
{
  if(obj == NULL) return -1;

  int ret = -1;

  if(index < obj->curSet)
  {
    if(empty(obj, index))       ret = stackOfPlatesPopAt(obj, index + 1);
    else                        ret =  *(--((obj->top)[index]));
  }
  else if(index == obj->curSet) ret = stackOfPlatesPop(obj);
  
  return ret;
}

void stackOfPlatesFree(StackOfPlates* obj) {

  if(obj == NULL) return;

  for(int i = 0; i < MAX_SET; i++)
    free((obj->stackBuf)[i]);
    
  free(obj);
}

```
