### 解题思路


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int storeNum (int max, int currNum, int *arr, int index) {
    /* base case */
    // if currNum is greater than the given number, return index wihout increment
    if (currNum > max) return index;
    // if currNum is not the first round then store currNum and increment index
    if (currNum != 0) {
        arr[index] = currNum;
        index++;
    }

    // store (0 ~ 9), (10 ~ 19), (100 ~ 109)... (20 ~ 29), (200 ~ 209)...
    for (int i = 0; i <= 9; i++) {
        // but 0 is not needed, skip 0
        if (currNum == 0 && i == 0) continue;
        // keep updating index
        index = storeNum(max, currNum*10 + i, arr, index);
    }
    return index;
}

int* lexicalOrder(int n, int* returnSize){
    int *arr = calloc((size_t)n, sizeof(int));
    int index = 0;
    storeNum (n, 0, arr, index);
    *returnSize = n;
    return arr;
}
```