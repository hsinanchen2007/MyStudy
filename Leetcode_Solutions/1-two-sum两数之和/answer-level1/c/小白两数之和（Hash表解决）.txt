 新手小白，刚开始学习数据结构，借鉴了各路大神的解法，采用hashmap实现两数之和。
参考文献：
C语言实现hashmap:[https://blog.csdn.net/u013799749/article/details/75674985]()

# 解题思路
实现Two Sum 如果通过暴力法是很容易解决的,若要考虑效率，可以采用hashmap减少查询的时间。
                 
- 标签：hash表
- 采用除留余数法构造hash，将`key`值作为`value`的索引，以`key-value`键值对的方式进行数据存储。
- 采用链地址法解决冲突，将冲突的hash值链接到链尾。
- 使用一层`for`循环遍历数组`nuns`，`i`为当前数组的下标，将`target`与遍历的每一个`nums[i]`产生差值,在hashmap中查找是否存在该值，若存在，则返回两个元素所在数组的下标。
- 时间复杂度:*O*(n)
- 空间复杂度:*O*(n)

```
typedef struct HashData
{
	int key;
	int value;
}HashData;

typedef struct HashNode
{
	HashData data;
	struct HashNode * next;
}HashNode;

typedef struct HashMap
{
	int size;
	HashNode * table;
}HashMap;

HashMap * CreateHashMap(int *nums,int numSize)
{
	int i;
	int index=0;
	HashMap *hashmap = (HashMap *)malloc(sizeof(HashMap));		
	hashmap->size = numSize;
	hashmap->table = (HashNode *)malloc(sizeof(HashNode)*hashmap->size);	

//初始化hash表
	for(i=0;i<hashmap->size;i++)
	{
		hashmap->table[i].data.value = INT_MIN;
		hashmap->table[i].next = NULL;
	}

//hash表创建
	while(index<numSize)
	{
		int place = abs(nums[index])%(hashmap->size);
		if(hashmap->table[place].data.value == INT_MIN)
		{
			//不冲突
			hashmap->table[place].data.value = nums[index];
			hashmap->table[place].data.key = index;
		}
		else
		{
			//冲突
			//给冲突的元素分配一个节点
			HashNode * node_1 = (HashNode *)malloc(sizeof(HashNode));
			HashNode * hashnode;
			node_1->data.value = nums[index];
			node_1->data.key = index;
			node_1->next = NULL;

			//将节点node_1 与next进行连接
			hashnode = &(hashmap->table[place]);
			while(hashnode->next != NULL)
			{
				hashnode = hashnode->next;
			}
			hashnode->next = node_1;
		}
		index++;
	}
	return hashmap;
}

int GetHashMap(HashMap * hashmap, int value)
{
	int place = abs(value)%(hashmap->size);
	HashNode * pointer = &(hashmap->table[place]);
	while(pointer != NULL)
	{
		if(pointer->data.value == value)
		{
			return pointer->data.key;
		}
		else
		{
			pointer = pointer->next;
		}
	}
	return -1;
}

void freeHashMap(HashMap * hashmap)
{
	int i=0;
	HashNode * Fpointer;
	while(i<hashmap->size)
	{
		Fpointer = hashmap->table[i].next;
		while(Fpointer != NULL)
		{
			hashmap->table[i].next = Fpointer->next;
			free(Fpointer);
			Fpointer = hashmap->table[i].next;
		}
		i++;
	}
	free(hashmap->table);
	free(hashmap);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i;
	int key=0;
	HashMap * hashmap = CreateHashMap(nums,numsSize);
	int * res = (int *)malloc(sizeof(int)*2);
	* returnSize = 0;
	for(i=0;i<numsSize;i++)
	{
		int value = target - nums[i]; 
		key = GetHashMap(hashmap,value);
		if(key !=-1 && key != i)
		{
			res[0] = i;
			res[1] = key;
            * returnSize=2;
			break;
		}
	}
	freeHashMap(hashmap);
	return res;
}
```



