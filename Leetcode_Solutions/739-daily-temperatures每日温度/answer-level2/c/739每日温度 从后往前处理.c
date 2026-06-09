/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void GetDays(int *arr, int arrlen, int idx, int *outArr) 
 {
     int j;
     for (j = idx + 1; j < arrlen; j = j + outArr[j]) {
         if (arr[j] > arr[idx]) {
             outArr[idx] = j - idx;
             break;
         } else if (outArr[j] == 0) { /* 说明arr数组j索引位置后面的元素都不大于arr【j】 */
            outArr[idx] = 0;
            break;
         }
     }

    return ; 
 }

int* dailyTemperatures(int* T, int TSize, int* returnSize) 
{
    int *retArr = (int *)malloc(sizeof(int) * TSize);
    memset(retArr, 0, sizeof(int) * TSize);

    int arrSize = TSize;
    *returnSize = arrSize;
    int i;

    /* 从后往前遍历元素 */
    for (i = arrSize - 2; i >= 0; i--) {
        GetDays(T, arrSize, i, retArr);
    }

    return retArr;
}