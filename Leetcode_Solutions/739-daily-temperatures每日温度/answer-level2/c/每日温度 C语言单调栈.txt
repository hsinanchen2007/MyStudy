### 解题思路
栈里存的是数组中的下标。
首先第一个元素入栈
之后每个元素入栈的时候：
如果比栈顶的数小，直接入栈。
如果比栈顶的数大，则栈顶的数出栈，继续和新的栈顶的数比较，直到栈顶的数比当前元素大，然后当前元素入栈

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *stack = (int *)calloc(TSize, sizeof(int));
    int top = 0;
    int *res = (int *)calloc(TSize, sizeof(int));
    
    stack[top++] = 0;
    
    for (int i = 1; i < TSize; i++) {
        if (T[stack[top - 1]] >= T[i]) {
            stack[top++] = i;
        } else {
            stack[top] = i;
            while (top > 0 && T[stack[top - 1]] < T[stack[top]]) {
                res[stack[top - 1]] = stack[top] - stack[top - 1];
                stack[top - 1] = stack[top];
                top--;
            }
            top++;
            
        }
    }
    *returnSize = TSize;
    return res;
}
```