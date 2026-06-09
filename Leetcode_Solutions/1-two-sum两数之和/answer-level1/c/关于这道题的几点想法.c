### 解题思路
使用暴力循环解出来的，没有费脑子，但是效率很低。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* returns = (int *)malloc(sizeof(int) * 2);
    int i = 0;
    int j = 1;
    * returnSize=0;
    for(i;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
             returns[0]=i;
             returns[1]=j;
             *returnSize = 2;
             return returns;
             }
        }
    }
    return returns;
}
```

1.题目明确说明返回数组需要自己分配内存，第一次审题完全忽略了这个问题。
2.对于题目中的返回，有误解，对于返回的结果以及书写还是有很大的问题。
