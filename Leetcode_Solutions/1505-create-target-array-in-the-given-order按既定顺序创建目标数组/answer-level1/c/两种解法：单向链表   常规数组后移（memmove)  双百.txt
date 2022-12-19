## 介绍
两种解法：单向链表   常规数组后移（memmove)  双百

## 1.单向链表
### 解题思路
插入操作，第一种想到的就是链表。耗时和内存和常规解法没有差别，但是手写还是有点耗时，建议面试的时候用常规解法。
1. 创建链表基本操作：创建和插入
2. 把nums根据index插入链表，要注意三个点
	(1) 头节点记录
	(2) 第一个节点的创建
	(3) 把节点插入到第一个位置时，需要注意插入顺序和判空
3. 根据节点输出返回结果
show code
```c
//单向链表
 struct list {
	int val;
	struct list* pNext;
};

//创建:创建一个值为val的结点
struct list* createNode(int val)
{
	struct list* pNode = calloc(sizeof(struct list), 1);
	pNode->pNext = NULL;
	pNode->val = val;

	return pNode;
}

//插入:在target后插入节点Node
void insertNode(struct list* pTargetNode, struct list* pNode)
{
	if (!pTargetNode)
	{
		return;
	}
	if (pTargetNode->pNext)	//非空节点,在链表头部增加时，需要进行判断，否则会出问题
		pNode->pNext = pTargetNode->pNext;
	pTargetNode->pNext = pNode;
	return;
}

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
	int* retArr = calloc(sizeof(int),indexSize);
	*returnSize = indexSize;

	int i = 0, j = 0;
	struct list* pNode = NULL;
	struct list* pHead = NULL;
	struct list* pTargetNode = NULL;

	for (i = 0; i<indexSize; i++)
	{
		pNode = createNode(nums[i]);    //创建一个节点
		if (0 == i) pHead = pNode;      //第一个为头节点
		else
		{
			pTargetNode = pHead;    //从头节点开始往后数，找到插入的节点
			j = index[i];
			if (0 == j)     //在链表头部插入
			{
				insertNode(pNode, pTargetNode);
				pHead = pNode;      //更新头节点
			}
			else        //非头部插入
			{
				j--;    
				while (j--)
				{
					pTargetNode = pTargetNode->pNext;
				}
				insertNode(pTargetNode, pNode);
			}

		}
	}

	pTargetNode = pHead;
	for (i = 0; i<indexSize; i++)
	{
		retArr[i] = pTargetNode->val;
		pTargetNode = pTargetNode->pNext;
	}
	return retArr;
}

```

## 2.常规解法
### 解题思路
不赘述了，使用memmove操作，避免了一个个数字的后移。
一开始memmove操作用错了，dst和src弄反了，原型是memmove(dst,src,size)，注意size是字节数,后移长度注意要修改，避免越界
memmove比较好用的是，不用在意内存地址重叠。

show code
```c
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
	int* retArr = calloc(sizeof(int),indexSize);
	*returnSize = indexSize;

    int i = 0;
    for(i=0;i<indexSize;i++)
    {
        memmove(&retArr[index[i]+1],&retArr[index[i]],sizeof(int)*indexSize-sizeof(int)*(index[i]+1));
        retArr[index[i]]=nums[i];
    }
    return retArr;
}

```