### 解题思路
---
---
####思路一：暴力法
---
1. 把最后一个元素`nums[numsSize-1]`保存在变量`value`中,
2. 数组每一个元素后移一位，
3. 令`nums[0]=value`
4. 重复以上步骤`k`次
`k=k%numsSize`是为了优化程序,但还是超时
### 代码
```c
void rotate(int* nums, int numsSize, int k)
{
    k = k%numsSize;
    int value;
    for(int i = 0;i<k;i++)
    {
        value = nums[numsSize-1];
        for(int j = numsSize-1;j>0;j--)
        {
            nums[j]=nums[j-1];
        }
        nums[0]=value;
    }
}
```
####思路二：三次反转法
---
例如`[1,2,3,4,5,6,7] k=3`
1. 1 2 3 4 5 6 7
2. 7 6 5 4 3 2 1
3. 5 6 7 1 2 3 4
既是为了防止溢出也是为了优化,一定要加上这条`k = k %numsSize`
### 代码

```c
void reverse(int* nums, int left, int right)
{
	int mid = (left + right) / 2;
	for (int i = right; i>mid; i--)
	{
		int temp = nums[i];
		nums[i] = nums[left + right - i];
		nums[left + right - i] = temp;
	}
}
void rotate(int* nums, int numsSize, int k) {
    k = k%numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k-1);
	reverse(nums, k, numsSize - 1);
}
```