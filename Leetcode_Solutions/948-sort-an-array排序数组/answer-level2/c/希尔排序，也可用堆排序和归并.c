### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //保证最后一次一定为1
		//控制循环次数 ，时间复杂度O(n^2)
		for (int i = 0; i < n - gap; ++i)
		{
			//每次把end 以后的数字插入前面的数中
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[gap + end] = tmp;
		}
	}
}
int* sortArray(int* nums, int numsSize, int* returnSize)
{
    ShellSort(nums,numsSize);
    *returnSize = numsSize;
    return nums;
}
```