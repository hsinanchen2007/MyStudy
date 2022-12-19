**//方法一
//暴力法时间复杂度O(n^2)
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

	int *lst = (int*)malloc(sizeof(int) * 2);

	lst[0] = 0;

	lst[1] = 0;
	for (int i = 0; i<numsSize - 1; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				lst[0] = i;
				lst[1] = j;
				*returnSize = 2;
				return lst;
			}
		}
	}
	return 0;

}




//方法二
//先将数组排序，后采用双指针搜索
//时间复杂度O（nlogn)

#include<stdio.h>
#include<stdlib.h>

//用于存储数组中每一个元素的值和对应的位置坐标结构体

struct Node
{

	int value;			//用于存储数组元素的值
	int pos;			//用于存储数组元素对应的坐标

};

//数组合并函数

void Merge(int L1, int R1, int L2, int R2, struct Node *lst)
{

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)*(R2 - L1 + 1));
	int i = L1;
	int j = L2;
	int index = 0;

	while (i <= R1&&j <= R2)
	{
		if (lst[i].value <=lst[j].value)
		{
			temp[index++] = lst[i++];
		}
		else
		{
			temp[index++] = lst[j++];
		}
	}

	while (i <=R1)
	{

		temp[index++] = lst[i++];
	}

	while (j <= R2)
	{

		temp[index++] = lst[j++];
	}

	for (int i = 0; i < index; i++)
	{
		lst[L1 + i] = temp[i];
	}

	free(temp);
}
//归并排序的主体

void MergeSort(int left,  int right, struct Node* lst)
{

	if (left < right)
	{

		int mid = (left + right) / 2;
		MergeSort(left, mid, lst);
		MergeSort(mid+1, right, lst);
		Merge(left, mid, mid + 1, right, lst);

	}

}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

	//lst用于存储排序好的数组

	struct Node *lst = (struct Node*)malloc(sizeof(struct Node)*numsSize);

	for (int i = 0; i < numsSize; i++)
	{

		lst[i].value = nums[i];
		lst[i].pos = i;

	}
	//调用归并排序

	MergeSort(0, numsSize - 1, lst);

	//用于判断是否满足题意，采用双指针搜索
	
	int i = 0;
	int j = numsSize-1;
	while (i < j)
	{
		if (lst[i].value + lst[j].value == target)
		{

			int *result = (int *)malloc(sizeof(int) * 2);
			result[0] = lst[i].pos;
			result[1] = lst[j].pos;
			*returnSize = 2;
			return result;
		}
		if (lst[i].value + lst[j].value < target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	free(lst);
	return 0;
}





//方法三
//采用哈希表（拉链法）
//时间复杂度O（n^2),但是运行时间相比与暴力法快了几十倍
//大致图形如下：
//				【address】->[ 节点]->[节点]->......
//				【address】->[ 节点]->[节点]->......
//				【address】->[ 节点]->[节点]->......
//				【address】->[ 节点]->[节点]->......
//					
//				其中address为链 首节点的地址
//
//
//
//用于记录每个节点的结构体


struct node
{

	int value;			//用于记录数组元素值的变量
	int pos;			//用于记录数组元素位置的变量
	struct node*next;	//用于记录下一个节点地址
};


//哈希表中的单元
struct hash
{

	struct node*add;
};


//用于释放malloc申请空间的函数
void hashfree(struct hash* point, int num)
{

	for (int i = 0; i < num; i++)
	{
		if (point[i].add)
		{
			struct node* Node = point[i].add;
			while (Node)
			{
				struct node*NextNode = Node->next;
				free(Node);
				Node = NextNode;
			}
		}
	}
	free(point);

}
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

	//建立哈希表，大小为numsSize（空间别忘了回收）
	struct hash * const Hash_Table = (struct hash*)malloc(sizeof(struct hash)*numsSize);
	
	//初始化哈希表
	for (int i = 0; i < numsSize; i++)
	{
		Hash_Table[i].add = NULL;
	}

	
	//初始化节点并将之添加到相应哈希表位置
	for (int i = 0; i < numsSize; i++)
	{
		//申请节点空间
		struct node* Node = (struct node*)malloc(sizeof(struct node));
		
		//初始化节点
		Node->value = nums[i];
		Node->pos = i;
		//计算节点添加到哈希表什么位置（由于题目所给数组元素可能为负数
		//为了简便直接采用绝对值函数,即-3和3存储在同一条链上）
		int mod = abs(nums[i]) % numsSize;

		//链上节点的添加采用前插法
		Node->next = Hash_Table[mod].add;
		Hash_Table[mod].add = Node;


		//计算所期望值在哈希表的位置
		//同理可能计算出为负值，因此采用取绝对值
		int expect = abs(target - nums[i]);

		//用于验证是否符合题目要求条件
		struct node* temp = Hash_Table[expect%numsSize].add;
		while (temp!=NULL)
		{
			if (temp->pos != i&&temp->value+nums[i]==target)
			{
				//符合题目条件
				int *result = (int *)malloc(sizeof(int) * 2);
				result[0] = temp->pos;
				result[1] = i;
				*returnSize = 2;
				hashfree(Hash_Table, numsSize);
				return result;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	*returnSize = 0;
	return 0;

}
```**