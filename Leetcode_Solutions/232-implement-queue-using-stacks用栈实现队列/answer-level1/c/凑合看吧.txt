### 解题思路
此处撰写解题思路

### 代码

```c
// 动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
// 检测栈是否为空，如果为空返回非零(1)，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}



typedef struct {
    Stack p1;
    Stack p2;        
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* p = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&p->p1);
    StackInit(&p->p2);
    return p;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
  StackPush(&obj->p1,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {

        if(StackEmpty(&obj->p1) == 0 && StackEmpty(&obj->p2) == 1)
    {
       while(!StackEmpty(&obj->p1))
        {
         int ret = StackTop(&obj->p1);
         StackPush(&obj->p2,ret);
         StackPop(&obj->p1);
        }
    }

          int ret = StackTop(&obj->p2);
         StackPop(&obj->p2);
      return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int ret = 0;
    if(StackEmpty(&obj->p1) == 0 && StackEmpty(&obj->p2) == 1)  //p1 非空 p2空 
    {
       while(!StackEmpty(&obj->p1))
        {
          ret = StackTop(&obj->p1);
         StackPush(&obj->p2,ret);
         StackPop(&obj->p1);
        }
        ret = StackTop(&obj->p2);
    }
    else if(StackEmpty(&obj->p1) == 1 && StackEmpty(&obj->p2) == 0)     //p1 空   p2 非空
    {
        ret = StackTop(&obj->p2);
    }
    else if(StackEmpty(&obj->p1) == 0 && StackEmpty(&obj->p2) == 0)     //p1 非空   p2 非空
    {
        ret = StackTop(&obj->p1);
    }
        
    return StackTop(&obj->p2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
  return StackEmpty(&obj->p1) && StackEmpty(&obj->p2);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->p1);
     StackDestroy(&obj->p2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
```