### 解题思路
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]




这样貌似快一些，　加个count记录的０个数，分count >= 2 count==1 count ==0 判断也行。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int i=0, product = 1;
    int *res = malloc(numsSize * sizeof(int));

    for (i = 0; i < numsSize; i++) {
        res[i] = product;
        product = product * nums[i];
    }

    product = 1;
    for (i = numsSize - 1; i >=0 ; i--) {
        res[i] = res[i] * product;
        product = nums[i]*product;
    }
    
    *returnSize = numsSize;
    return res;
}
```