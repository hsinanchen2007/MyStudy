### 解题思路
遇到数字就入栈，遇到符号就分别取2个栈顶元素 后者置于运算符左边，前者置于右边，再把计算结果入栈，循环直到结束，栈中剩下的就是结果


### 代码

```c


// 动态增长的栈
typedef int STDataType;   //类型可以自己定义
typedef struct Stack
{
	STDataType* _a;  //数组
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
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;     //空了就开
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));   //扩容
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



int evalRPN(char ** tokens, int tokensSize)
{
    Stack p;
    StackInit(&p);
    for(int i = 0; i < tokensSize; ++i)
    {
        if(tokens[i][1] == '\0' && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
        {
            int a = StackTop(&p);
           // printf("@ %d\n",a);
            StackPop(&p);
            int b = StackTop(&p);
           // printf("# %d\n",b);
            StackPop(&p);
            int c = 0;
            switch(tokens[i][0])
            {
                case '+': c = b + a;
                    break;
                case '-': c = b - a;
                    break;
                case '*': c = b * a;
                    break;
                case '/': c = b / a;
                    break;
                default:
                    break;
            }
            //printf("$ %d\n",c);
            StackPush(&p,c);
        }
        else
        {
            
            StackPush(&p,atoi(tokens[i]));
           // printf("! %d\n",StackTop(&p));
        }
    }
    return StackTop(&p);

}
```