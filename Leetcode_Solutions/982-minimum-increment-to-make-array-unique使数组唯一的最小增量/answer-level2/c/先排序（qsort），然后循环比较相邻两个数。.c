### 解题思路
此处撰写解题思路
先排序，然后从小到大依次比较相邻两个数的大小，如果前一个数大于后一个数，则将后一个数加到刚好比前一个数大1.以此类推。
使用C语言的qsort（快排序）对数组进行排序。
### 代码

```c
int comp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}  

int minIncrementForUnique(int* A, int ASize){
	qsort(A,ASize,sizeof(int),comp);
	int count=0;
	for(int i=0;i<ASize-1;i++)
	{
		if(A[i+1]<=A[i])
		{
			count+=A[i]-A[i+1]+1;
			A[i+1]=A[i]+1;
		}
	}
	return count;
}
```