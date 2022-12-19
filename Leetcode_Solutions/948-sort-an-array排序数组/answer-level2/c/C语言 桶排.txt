### 解题思路
![1585625079(1).jpg](https://pic.leetcode-cn.com/48e6b0a8d50394b6d62987d8cc20044b704585e02b68609945b17fc2315b8ee6-1585625079\(1\).jpg)


1.求出最大值和最小值找到排序区间
2.初始化区间数组
3.遍历一遍待排序的序列，将对应的值放入桶中，桶中值代表个数，桶中的值+1
4.根据需要从后往前或者从前往后将桶中的值输出即可

复杂度为2*(m + n)
相比较固定区间的桶排，求出准确的区间可以降低空间和时间复杂度

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if (numsSize < 2)
        return nums;
    int min = nums[0], max = nums[0], i = 0, j = 0;
    for (; i < numsSize; ++i){
        min = min < nums[i] ? min : nums[i];
        max = max > nums[i] ? max : nums[i];
    }
    int value = max - min + 1;
    int result[value];
    for (i = 0; i < value; ++i)
        result[i] = 0;
    for (i = 0; i < numsSize; ++i)
        ++result[nums[i] - min];
    for (i = 0; i < value; ++i)
        while (result[i]--)
            nums[j++] = i + min;
    return nums;
}
```