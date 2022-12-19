### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(void *x, void *y)
 {
     return *(int *)x - *(int *)y;
 }

int* numMovesStones(int a, int b, int c, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 2);
    int minCnt = 0;
    int arrTemp[3] = {a, b, c};
    
    qsort(arrTemp, 3, sizeof(int), cmp);
    arr[0] = 0;
    arr[1] = 0;
    *returnSize = 2;

    /* 如果是连续数组，则不用移动 */
    if ((arrTemp[1] - arrTemp[0] == 1) && (arrTemp[2] - arrTemp[1] == 1)) {
        return arr;
    }
    arr[1] = arrTemp[2] - arrTemp[0] - 2;
    /* 最小值移动次数 */
    if ((arrTemp[1] - arrTemp[0] <= 2) || (arrTemp[2] - arrTemp[1] <= 2)) {
        arr[0] = 1;
    } else {
        arr[0] = 2;
    }

    return arr;
}


```