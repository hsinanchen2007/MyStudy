### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *result;
    int *stack;
    result=(int *)malloc(sizeof(int)*TSize);
    stack=(int *)malloc(sizeof(int)*TSize);
    memset(result,0,sizeof(int)*TSize);
    int i=0;
    int top=-1;
    for(i=0;i<TSize;i++)
    {
        while(top>=0&&T[i]>T[stack[top]])//因为此处判断将top>=0放了后边浪费了半个小时，怎么也没想到会是这里越界，希望能有人解答。
        {
            result[stack[top]]=i-stack[top];
            top--;
        }
        stack[++top]=i;
    }
    *returnSize=TSize;
    free(stack);
    return result;
}
```