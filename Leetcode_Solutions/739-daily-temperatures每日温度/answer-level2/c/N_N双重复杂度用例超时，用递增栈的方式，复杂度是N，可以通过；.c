### 解题思路
N*N双重复杂度用例超时，用递增栈的方式，复杂度是N，可以通过；

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize)
{

    int *result = NULL;
    int *stack = NULL;
    int i, j;
    int s_top = -1;

    *returnSize = TSize;
    if (TSize == 0)
        return NULL;

    result = (int*) malloc(sizeof(int) * (TSize + 1));
    stack = (int*) malloc(sizeof(int) * (TSize + 1));

    for (i = 0; i < TSize; i++) {
        result[i] = 0;
    }

    for (i = 0; i < TSize; i++) {
        if (s_top == -1) {
            stack[s_top + 1] = i;
            s_top++;
            continue;
        }

        for (j = s_top; j >= 0; j--) {
            if (T[stack[j]] < T[i]) {
                result[stack[j]] = i - stack[j];
                s_top--;
            }
            else
                break;
        }

        stack[s_top + 1] = i;
        s_top++;
    }

    return result;
}

```