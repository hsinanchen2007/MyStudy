### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;

    int i, j, max, val;
    max = -1;
    for (i = 0; i < arrSize - 1; i++) {
        if (i < max) {
            arr[i] = arr[max];
        }
        else {
            val = 0;
            for (j = i + 1; j < arrSize; j++) {
                if (arr[j] > val) {
                    max = j;
                    val = arr[j];
                }
            }
            arr[i] = arr[max];
        }
    }
    arr[i] = -1;

    return arr;
}
```