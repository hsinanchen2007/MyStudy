### 解题思路
从左向右查找第一个最大，转变为从由向左的单调递增栈，这样栈顶是当前从左往右最小值。
这样只要在单调递增栈中出栈查找最近的。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *pRet = NULL;
    *returnSize = 0;
    int *pStack = (int *)malloc(TSize * sizeof(int));
    if((T == NULL) || (pStack == NULL) || (TSize < 1)) {
        goto ERR;
    }
    pRet =  (int *)malloc(TSize * sizeof(int));
    if (pRet == NULL) {
        goto ERR;
    }
    int stackPos = 0;
    pRet[TSize - 1] = 0; // the last have no bigger later
    pStack[stackPos] = (TSize - 1); // the index
    for(int i = (TSize - 2); i >= 0; i--) {

        while (stackPos >= 0) {
            if (T[i] < T[pStack[stackPos]]) {
                pRet[i] = (pStack[stackPos] - i);
                stackPos++;
                pStack[stackPos] = i;
                break;
            }
            stackPos--;  // pop stack
        }
        if (stackPos == (-1)) { // No bigger
            stackPos++; // stackPos is -1,the first.
            pStack[stackPos] = i; // Push stack with the current possion
            pRet[i] = 0;
        }
    }
    *returnSize = TSize;
ERR:
    if (pStack != NULL) {
        free(pStack);
    }
    return pRet;
}
```