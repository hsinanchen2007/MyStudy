### 解题思路
单调栈练习
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *result = NULL;
    int *stack = NULL;
    int index;
    int top = -1; // 栈顶索引

    result = (int *)calloc(numsSize, sizeof(int)); // 保存结果
    stack = (int *)calloc(2 * numsSize + 1, sizeof(int)); // 数组模拟单调栈
    memset(result, -1, sizeof(int) * numsSize); // memset初始化动态数组

    // 如果栈顶比下一个小，则找到结果，将比下一个元素小的元素出栈，并将下一个入栈
    // 如果栈顶不比下一个小，则直接将下一个入栈
    // 因为是循环，所有将数组*2 [1,2,3,4] -> [1,2,3,4,1,2,3,4]
    // 为了方便，不直接入数组值，而是入数组索引
    // 第一个元素不用和自己比较，所以直接入栈

    for(int i = 0; i < 2 * numsSize; i++) {
        index = i % numsSize; // 防止越界
    
        while (top > -1 && nums[stack[top]] < nums[index]) {
            result[stack[top--]] = nums[index];
        }
   
        stack[++top] = index;
    }
    
    free(stack);
    *returnSize = numsSize;
    return result;
}
```