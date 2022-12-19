### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*
    问题转化为：比当前位置大的最近的数的距离，单调栈
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize) {

    //int stack[1000] = {0};
    int top = 0;

    /* 无条件入栈，但是如果不满足单调栈条件需要弹出栈中数据 */

    /*
         单调递减栈，遇到比栈顶大的，说明找到了第一个比栈顶元素大的数，把栈顶处理完弹出，继续处理栈顶
         直到满足单调栈的条件
    */
    int *stack = (int *)malloc(TSize * sizeof(int));
    int *res = (int *)malloc(TSize * sizeof(int));
    memset(res, 0, sizeof(int)*TSize);
    for (int i = 0; i< TSize; i++) {
        while ((top != 0) && (T[stack[top-1]] < T[i])) {
            /* 满足出栈条件 */
            res[stack[top-1]] = (i - stack[top-1]);
            top--;
        }
        stack[top++] = i; /* 将当前索引压入栈,栈中的索引都是还没有找到目标值的 */
    }
    *returnSize = TSize;
    return res;

}
```