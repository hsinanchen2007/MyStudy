### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/767ab8e4c61b9b6fcae3f62c9ee9447f3ce7dc0fbc84dd351b4e5fe43f1bdcd0-image.png)
1、对数组使用qsort库函数排序：从小到大
2、直接返回nums[numsSize - k]

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize - k];
}
```