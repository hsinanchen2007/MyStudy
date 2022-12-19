### 解题思路
位数很多，只能一位一位计算

### 代码

```c
//链表节点
typedef struct Node {
	int data;
	struct Node* next;
}Node;
//新建节点
Node* newNode(int Data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = Data;
	n->next = 0;
	return n;
}
//入栈
void stackPush(Node* Head, int Data)
{
	Node* n = newNode(Data);
	n->next = Head->next;
	Head->next = n;
}
//统计站内元素数量
int stackLength(Node* Head)
{
	int length = 0;
	while (Head != 0)
	{
		++length;
		Head = Head->next;
	}
	return length - 1;
}
//释放栈内存
void stackDel(Node* Head)
{
	while (Head != 0)
	{
		Node* del = Head;
		Head = Head->next;
		free(del);
	}
}

char * addBinary(char * a, char * b) {

	//为字符串a和b准备栈
	Node* stackA = newNode(-1);
	Node* stackB = newNode(-1);
	//a b 入栈
	while (*a != '\0')
	{
		if (*a == '0')
			stackPush(stackA, 0);
		else
			stackPush(stackA, 1);
		++a;
	}
	while (*b != '\0')
	{
		if (*b == '0')
			stackPush(stackB, 0);
		else
			stackPush(stackB, 1);
		++b;
	}
	//相加 flag是进位标志 栈顶是低位，从栈顶开始加
	int flag = 0;
	Node* stackSum = newNode(-1);
	Node* iterA = stackA->next;
	Node* iterB = stackB->next;
	//两个栈都非空的时候
	while (iterA != 0 && iterB != 0)
	{
		//根据进位标志确定本位的初始数据
		int sum = flag ? iterA->data + iterB->data + 1 : iterA->data + iterB->data;
		//重新处理进位标志
		flag = sum > 1 ? 1 : 0;
		//把相加结果存入“结果栈”
		stackPush(stackSum, sum % 2);

		iterA=iterA->next;
		iterB = iterB->next;
	}
	//处理一下剩下的数据
	while (iterA != 0)
	{
		int sum = flag ? iterA->data + 1 : iterA->data;
		flag = sum > 1 ? 1 : 0;
		stackPush(stackSum, sum % 2);
		iterA = iterA->next;
	}
	while (iterB != 0)
	{
		int sum = flag ? iterB->data + 1 : iterB->data;
		flag = sum > 1 ? 1 : 0;
		stackPush(stackSum, sum % 2);
		iterB = iterB->next;
	}
	//最后看一下还有没有进位
	if (flag)
		stackPush(stackSum, 1);
	//释放两个栈内存
	stackDel(stackA);
	stackDel(stackB);

	//处理“结果栈”
	int length = stackLength(stackSum);
	char *result = (char*)malloc(sizeof(char)*(length + 1));
	Node* iterSum = stackSum->next;
	int iterResult = 0;
	while (iterSum != 0)
	{
		result[iterResult++] = '0' + iterSum->data;
		iterSum = iterSum->next;
	}
	result[iterResult] = '\0';
	stackDel(stackSum);

	return result;
}

/* 不能用位运算，输入会很长很长
char * addBinary(char * a, char * b){
    unsigned bitA=0,bitB=0;
    while(*a!='\0')
    {
        if(*a=='0')
            bitA=(bitA<<1)|((unsigned)0);
        else
            bitA=(bitA<<1)|((unsigned)1);
        ++a;
    }
    while(*b!='\0')
    {
        if(*b=='0')
            bitB=(bitB<<1)|((unsigned)0);
        else
            bitB=(bitB<<1)|((unsigned)1);
        ++b;
    }
    unsigned bitSum=bitA+bitB;
    if(bitSum==0)
    {
        char* result=(char*)malloc(sizeof(char)*2);
        result[0]='0';
        result[1]='\0';
        return result;
    }

    unsigned bits=bitSum;
    int length=0;
    while(bits!=0)
    {
        ++length;
        bits/=2;
    }

    char* result=(char*)malloc(sizeof(char)*(length+1));
    result[length]='\0';
    for(int i=length-1;i>=0;--i)
    {
        result[i]='0'+bitSum%2;
        bitSum/=2;        
    }

    return result;
}*/
```