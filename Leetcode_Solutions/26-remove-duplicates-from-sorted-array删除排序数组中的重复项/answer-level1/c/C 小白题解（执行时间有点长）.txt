### 解题思路
此处撰写解题思路
执行用时 :412 ms, 在所有 C 提交中击败了8.67%的用户
内存消耗 :9.4 MB, 在所有 C 提交中击败了96.86%的用户
没想到时间有了这麽长，先去看下大佬的解法，一会写心得
### 代码

```c
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int a = *nums, sum = 1, i = 1, j;
	while (i < numsSize)
	{
		if (nums[i] != a)
		{
			a = nums[i];
			i++;
		}
		else {
			j = i;
			while (j + 1 < numsSize)
			{
				nums[j] = nums[j + 1];
				j++;
			}
			numsSize--;
		}
	}

	return numsSize;
}
```