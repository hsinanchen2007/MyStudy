### 解题思路
数组模拟栈，sscanf获取输入

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char ** logs, int logsSize, int* returnSize){

    int *result = (int *)malloc(sizeof(int) * n);
    memset(result, 0, sizeof(int) * n);

    int *stack = (int *)malloc(sizeof(int) * logsSize);
    memset(stack, 0, sizeof(int) * logsSize);

    int top = -1;

    int id;
    int currTime, prevTime;
    char action[6];

    for (int i = 0; i < logsSize; i++) {
        sscanf(logs[i], "%d:%[a-z]:%d", &id, action, &currTime);
        if (action[0] == 's') {
            if (top >= 0) {
                result[stack[top]] += currTime - prevTime;
            }
            top++;
            stack[top] = id;
            prevTime = currTime;
        } else {
            result[stack[top]] += currTime - prevTime + 1;
            top--;
            prevTime = currTime + 1;
        }
    }
    free(stack);

    *returnSize = n;
    return result;
}
```