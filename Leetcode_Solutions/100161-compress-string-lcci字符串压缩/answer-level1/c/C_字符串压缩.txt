### 解题思路
利用链表队列进行压缩

注意特殊情况 aaaaaaaaaa->a10，压缩后数字是两位的

总结:需要缓存空间，但是大小未定，用链表当做缓存空间可以节省空间。（内存消耗 :8.2 MB, 在所有 C 提交中击败了100.00%的用户）

### 代码

```c
//队列节点
typedef struct Node {
	char data;
	struct Node* next;
}Node;
//新建节点
Node* newNode(char Datal)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = Datal;
	n->next = 0;
	return n;
}
//入队:队列的入队是从尾插入，有一个尾指针后移的动作，但是函数的值传递方式是不能改变尾指针的值的，所以要传递尾指针的地址
void push(Node** AddressOfRear, char Data)
{
	Node* n = newNode(Data);
	n->next = (*AddressOfRear)->next;
	(*AddressOfRear)->next = n;
	(*AddressOfRear) = (*AddressOfRear)->next;
}
//出队
char pop(Node* Head)
{
	Node* del = Head->next;
	Head->next = del->next;
	char result = del->data;
	free(del);
	return result;
}
//队列内元素长度
int lengthOf(Node* Head)
{
	int result = 0;
	for (Node* iter = Head->next; iter != 0; iter = iter->next)
		++result;
	return result;
}
//把一个字符和它连续出现的次数编排好送入队列
void addDataAndTime(Node** AddressOfRear, char Data, int Times)
{
	//字符先入队
	push(AddressOfRear, Data);
	//出现的次数可能只有一位数字，也可能有多位数字，从低位到高位入队
	while (Times != 0)
	{
		//数字拆分成一位一位之后，队尾节点当做一个链表头结点，用头插法插入，防止Times翻转
		Node* n = newNode('0' + Times % 10);
		n->next = (*AddressOfRear)->next;
		(*AddressOfRear)->next = n;
		Times /= 10;
	}
	//队尾指针向后移到插入数字后的队尾
	while ((*AddressOfRear)->next != 0)
		(*AddressOfRear) = (*AddressOfRear)->next;

}
//释放队列内存
void del(Node* Head)
{
	while (Head != 0)
	{
		Node* del = Head;
		Head = Head->next;
		free(del);
	}
}

char* compressString(char* S) {
	//建队列头结点、尾指针
	Node* head = newNode('\0');
	Node* rear = head;
	//压缩后的字符串
	char* result;
	//压缩前字符串的长度
	int strLength = 0;
	//迭代字符进行压缩
	char* iter = S;
	while (*iter != '\0')
	{
		//统计连续相同字符子串长度
		int length = 0;
		char c = *iter;
		while (*iter == c)
		{
			++length;
			++iter;
			++strLength;
		}
		//压缩
		addDataAndTime(&rear, c, length);
	}
	//测量压缩后的字符串长度
	int zipLength = lengthOf(head);
	//不小于压缩前的字符串就不压缩
	if (zipLength >= strLength)
	{
		del(head);
		return S;
	}
	else
	{
		//把队列里的数据整理成压缩字符串
		result = (char*)malloc(sizeof(char)*(zipLength + 1));
		for (int i = 0; i < zipLength; ++i)
			result[i] = pop(head);
		result[zipLength] = '\0';
		del(head);
		return result;
	}
}
```