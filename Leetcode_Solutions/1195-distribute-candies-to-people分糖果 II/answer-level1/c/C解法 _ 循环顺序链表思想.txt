### 解题思路

看到从最后一个返回到第一个 最先想到的就是循环链表
循环顺序链表用数组实现，用取余操作返回第一个

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize = num_people;
    int *ans = (int *)malloc(num_people*sizeof(int));
    for (int i=0;i<num_people;i++)
    {
        ans[i] = 0;
    }

	int k=1;
	int i=0;
	ans[i]=k;i++;k++;
	candies--;
	while(candies>k)
	{
		ans[i%num_people]+=k;
		i=i%num_people+1;
		candies-=k;
		k++;
	}
	ans[i%num_people]+=candies;
	return ans;

}
```