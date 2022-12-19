### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/9ad734fbc67a0810f86639873b4f6b942169c6130ec01702512b115c9feda44c-image.png)
 维护一个单调栈，由栈顶至栈底由小到大。
（1）当遍历到数组的一个新的元素时，若栈顶比该元素小，那么对此时的栈顶来说，找到了下一个更大元素，便从栈中弹出。继续判断栈顶是否小于该元素，小于则弹出，直到栈为空或栈顶大于该元素。
（2）当栈为空或栈顶大于该元素时，直接将该元素入栈。

由于本题中未规定数组中元素无重复，所以为了唯一识别一个元素，栈中需要保存数组的索引，而不是数组元素的值。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 10000
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *stack = calloc(MAX_NUM, sizeof(int)); /* 模拟栈 */
    int *result = calloc(numsSize, sizeof(int));
    int top = -1;/* 模拟栈顶 */
    memset(result, -1, sizeof(int) * numsSize);
    for (int i = 0; i < 2 * numsSize -1; i++) {
        int idex = i % numsSize;/* 取模，才能防止下标溢出 */
        while (top > -1 && nums[stack[top]] < nums[idex]) { /* 出栈 */
            result[stack[top--]] = nums[idex];
        }
        stack[++top] = idex;/* 入栈 */
    }
    *returnSize = numsSize;
    free(stack);
    return result;
}
```