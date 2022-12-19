解题思路：
1. 因为C语言的性质，用车就要先造车。先用C语言实现一个栈。
2. 实例化两个栈，一个存放输入的所有数据、一个存放当前输入数据中的最小值（保证第二个栈中栈栈顶元素是第一个栈中所有元素中最小的）。
3. 然后就根据题目意思，完成要求。
![111.png](https://pic.leetcode-cn.com/94bae1ae1f7d361b26f6994969c6f5b54d6b9751184cbfe0e0012927c5be3427-111.png)

```c
typedef int STDataType;

typedef struct Stack
{
	STDataType* _array;
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* ps);//初始化
void StackDestory(Stack* ps);//销毁
void StackPush(Stack* ps, STDataType x);//尾插
void StackPop(Stack* ps);//尾删
STDataType StackTop(Stack* ps);//取到当前栈顶元素
int StackEmpty(Stack* ps);//判断栈是否为空
int StackSize(Stack* ps);//判断栈中的元素个数


void StackInit(Stack* ps)//初始化
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackDestory(Stack* ps)//销毁
{
	assert(ps && ps->_array != NULL);

	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)//尾插
{
	assert(ps);
    
	if (ps->_top == ps->_capacity)//判断容量是否够用
	{
		size_t new_capacity = ps->_array == 0 ? 8 : (ps->_capacity) * 2;//三目运算符判断容量是否够用
		ps->_array = (STDataType*)realloc(ps->_array, new_capacity*sizeof(STDataType));
		assert(ps->_array);//判断是否申请到内存
		ps->_capacity = new_capacity;
	}
	//插入数据
	ps->_array[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)//尾删
{
	assert(ps && ps->_array != NULL);

	--ps->_top;//把栈顶指针向前移动一位，完成出栈
}

STDataType StackTop(Stack* ps)//取到当前栈顶元素
{
	assert(ps && ps->_array != NULL);

	return ps->_array[ps->_top - 1];
}

int StackEmpty(Stack* ps)//判断栈是否为空
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)//判断栈中的元素个数
{
	assert(ps);

	return ps->_top;
}


typedef struct {
    Stack q1;
    Stack q2;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* st = (MinStack*)malloc(sizeof(MinStack));
    StackInit(&st->q1);
    StackInit(&st->q2);
    
    return st;
}

void minStackPush(MinStack* obj, int x) {
  StackPush(&obj->q1,x);
    if(StackEmpty(&obj->q2) == 0)
    {
         StackPush(&obj->q2,x);
    }
    else
    {
        if(StackTop(&obj->q2) >= x)
        {
             StackPush(&obj->q2,x);
        }
    }
}

void minStackPop(MinStack* obj) {
  if(StackTop(&obj->q1) == StackTop(&obj->q2))
  {
      StackPop(&obj->q1);
      StackPop(&obj->q2); 
  }
  else
  {
      StackPop(&obj->q1);   
  }
}

int minStackTop(MinStack* obj) {
  return StackTop(&obj->q1);
}

int minStackGetMin(MinStack* obj) {
  return StackTop((&obj->q2));
}

void minStackFree(MinStack* obj) {
    StackDestory(&obj->q1);
    StackDestory(&obj->q2);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
