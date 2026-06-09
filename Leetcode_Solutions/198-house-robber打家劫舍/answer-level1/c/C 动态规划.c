### 解题思路
动态规划，递归之后，记录之前计算的结果。

### 代码

```c

int maxNum(int num1,int num2)
{
    return num1>num2 ? num1:num2;
}

int rob(int* nums, int numsSize) {
    int* resultArray = NULL;
    int result = 0;
    resultArray = (int*)malloc(sizeof(int) * numsSize);
    memset(resultArray, 0, sizeof(int) * numsSize);

    if ((NULL == nums)||(numsSize == 0)) {
        return 0;
    }
    if (numsSize == 1) {
        return *nums;
    }
    if (numsSize == 2) {
        return maxNum(*nums, *(nums+1));
    }

    *resultArray = *nums;
    *(resultArray + 1) = maxNum(*nums, *(nums + 1));
   
    for (int i = 2; i<numsSize; i++) {    
        *(resultArray + i) = maxNum(*(resultArray + i - 1), (*(resultArray + i - 2) + *(nums + i)));
    }
   /* 曾经尝试用递归超超时了
    return maxNum(rob(nums, numsSize-1), rob(nums, numsSize-2) + *(nums + numsSize - 1));
   */
   result = *(resultArray + numsSize -1);
   free(resultArray);
   return result;
}
```