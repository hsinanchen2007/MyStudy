### 解题思路
此处撰写解题思路

### 代码

```c
inline int Max(int a, int b)
{
    return a > b ? a : b;
}

bool canJump(int* nums, int numsSize){
	int k = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (i > k) return false;
		k = Max(k, i + nums[i]);
	}
	return true;
}
```