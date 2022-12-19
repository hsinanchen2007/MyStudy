### 解题思路
哈哈哈讲一讲我犯的错误
第一次是没考虑到输入为空数组的情况
第二次是把英文分号打成了中文分号
噗

### 代码

```c
int findLengthOfLCIS(int* nums, int numsSize){
if(numsSize==0)
return 0;
int length = 1;
	int len = 1;
	int i = 1;
	for (i; i < numsSize; i++)
	{
		if (nums[i] > nums[i - 1])
			len++;
		else
			len = 1;
		if (len > length)
			length = len;
	}
	return length;
}
```