### 解题思路
不能对数组先排序再统计，会超时。
建立一个链表，链表中的每一个节点代表一种数字。遍历数组一遍之后用链表统计好出现次数，输出。

### 代码

```c
typedef struct Node{
    int data;//数字
    int times;//出现次数
    struct Node* next;//下一节点地址
}Node;
//新建节点
Node* newNode(int Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->times=1;
    n->next=0;
    return n;
}
//返回数字Data在数组中出现的次数
int timesOfNum(Node* Head,int Data)
{
    //链表是带头结点的，计算的时候从头结点后面开始计算
    Node* n=Head->next;
    //找出Data在链表中对应的节点
    while(n!=0&&n->data!=Data)
        n=n->next;
    //链表中没有Data对应的节点，就新建一个加入链表
    if(n==0)
    {
        n=newNode(Data);
        n->next=Head->next;
        Head->next=n;
    }
    //链表中有Data对应的节点，计数值加一
    else
        ++(n->times);
    //返回计数值
    return n->times;
}
//销毁链表，释放内存
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}

int majorityElement(int* nums,int numsSize){
    //存放结果
    int result;
    //建立链表头节点
    Node* head=newNode(0);
    //遍历数组，判断每种数字出现的次数是不是超过了（总数÷2），是则返回这种数字，不是就查看下一个。
    for(int i=0;i<numsSize;++i)
        if(timesOfNum(head,nums[i])>numsSize/2)
        {
            result=nums[i];
            break;
        }
    //释放内存
    del(head);
    return result;
}


/* 先排序再统计 会超时
int majorityElement(int* nums, int numsSize) {
	for (int i = 0; i < numsSize - 1; ++i)
		for (int j = 0; j < numsSize - i - 1; ++j)
			if (nums[j] > nums[j + 1])
			{
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}

	int Times = 0, Num = nums[0];
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == Num)
			++Times;
		else
			if (Times > numsSize / 2)
				return Num;
			else
			{
				Num = nums[i];
				Times = 1;
			}
	}
	return Num;
}*/
```