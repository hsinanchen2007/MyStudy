### 解题思路
  这次代码我觉得比较好看得懂。但是内存消耗较大，如果有好的完善方法可以在下面评论下

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
	int count = 1;
	int t = nums[0];
	for (int i = 1; i <=numsSize-1; i++)
	{
		if (nums[i]==t) {
			continue;
		}
		else
		{
			nums[count] = nums[i];
			t = nums[i];
			count++;
		}
	}
	return count;
}
```