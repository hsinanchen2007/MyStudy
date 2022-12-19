### 解题思路
一个栈用来进数据，当出数据时将非空栈中数据入空栈中
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
} CQueue;


CQueue* cQueueCreate() 
{
    CQueue* p = (CQueue*)malloc(sizeof(CQueue));
    StackInit(&p->p1);
    StackInit(&p->p2);
    return p;
}

void cQueueAppendTail(CQueue* obj, int value)
{
     StackPush(&obj->p1,value);    //数据永远入p1
}

int cQueueDeleteHead(CQueue* obj)
{
    if(StackEmpty(&obj->p1) == 1 && StackEmpty(&obj->p2) == 1)  //p1、p2皆空反-1
        return -1;
    if(StackEmpty(&obj->p1) == 0 && StackEmpty(&obj->p2) == 1)  //p1非空p2空，将数据导入p2
    {
        while(!StackEmpty(&obj->p1))
        {
            int ret = StackTop(&obj->p1);
            StackPop(&obj->p1);
            StackPush(&obj->p2,ret);
        }
    }
    int ret = StackTop(&obj->p2);
    StackPop(&obj->p2);
    return ret;
}

void cQueueFree(CQueue* obj) 
{
    StackDestroy(&obj->p1);
    StackDestroy(&obj->p2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
```