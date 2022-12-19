### 解题思路

采用哈希表来做。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 特别注意：该程序如果有多个结果符合，只返回排在前面的。
// 哈希表的创建采用动态数组申请
// 哈希函数采用除留取余法
// 哈希冲突解决办法采用链地址法
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LoadFactor 0.5    //哈希表装填因子

typedef struct LNode    //链表结构体
{
    int data;
    int index;
    struct LNode *next;
}LNode; 
typedef struct HashTb   //哈希表结构体
{
    int table_size;
    struct LNode **TheLists;
                    //结构体指针数组，数组的每个元素是一个指向链表结构体的指针
}HashTb;

int isPrime(int n)
{
	if (n <= 1)
	    return 0;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n%i == 0)
			return 0;
	return 1;
}

int nextPrime(int n)
{
	int i = n - 1;
	if (n <= 2)
	{
		printf("Error");
	}
	else
	{
		while (!isPrime(i))
			--i;
	}
	return i;
}

int hashFun(int key, int p)
{
	return abs(key) % p;
}

HashTb* hashTableInit(int hash_table_size)      //建立哈希表
{
    HashTb *H;
    H = (HashTb*)calloc(1, sizeof(HashTb));
	if(NULL == H)
	{
		printf("insufficient memory!\n");
        exit(0);
	}
    H->table_size = nextPrime(hash_table_size);
    //------------------------------------------------------//    
    H->TheLists = (LNode**)calloc(H->table_size, sizeof(LNode*));
    if(NULL == H->TheLists)
	{
		printf("Insufficient memory!\n");
		exit(0);
	}
    for(int i = 0; i < H->table_size; i++)
	{
		H->TheLists[i] = (LNode*)calloc(1, sizeof(LNode));
		if(NULL == H->TheLists[i])
		{
			printf("Insufficient memory!\n");
			exit(0);
		}
		H->TheLists[i]->next = NULL;
	}
    return H;
}

LNode* hashFindKey(int key, HashTb *H)
{
    LNode* p;
    LNode* L;

    if (H != NULL)
    {
        L = H->TheLists[hashFun(key, H->table_size)];
    }
    for(p = L->next; p != NULL; p = p->next)
	{
		if(p->data == key)
		    break;
	}
	return p;
}

void hashInsert(int number, int position, HashTb *H)
{
    if(1)
	{
		LNode *L = H->TheLists[hashFun(number, H->table_size)];
        LNode *newnode = (LNode*)calloc(1, sizeof(LNode));
        if(NULL == newnode)
	    {
		    printf("Insufficient memory !\n");
		    exit(0);
	    }
        newnode->data = number;
        newnode->index = position;
		newnode->next = L->next;
        L->next = newnode;
	}
}

void hashFree(HashTb *H)
{
	LNode *q, *p;
	for(int i = 0; i < H->table_size; i++)
	{
        p = H->TheLists[i];
	    while(p->next != NULL)
	    {
		    q = p->next;
            p->next = p->next->next;
		    free(q);
	    }
	}
    free(H->TheLists);
	free(H);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    HashTb *H;
    int *result = (int*)calloc(2, sizeof(int));
    result[0] = -1;
    result[1] = -1;
    int list_len = numsSize / LoadFactor;   //求出哈希表长
    H = hashTableInit(list_len);
    for (int i = 0; i < numsSize; i++)
    {
        int key = target - nums[i];
        LNode* p = hashFindKey(key, H);
        if (p != NULL)
        {
            result[0] = p->index;
            result[1] = i;
            returnSize[0] = 2;
            hashFree(H);
            return result;  
        }
        else
        {
            hashInsert(nums[i], i, H);
        }
    }
    hashFree(H);
    returnSize[0] = 0;
    return result;  
}

```