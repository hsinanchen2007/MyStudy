### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 bool GetNextNum(int start, int target, int *cnt){
     //printf("%d:%d\n", start, target);
     if (start == target){
         (*cnt)++;
         return true;
     } if (start > target) {
         return false;
     }
     (*cnt)++;
     return GetNextNum(start + 1, target - start, cnt);
 }
 int *OutOneArray(int start, int cnt){
     int *arr = malloc(sizeof(int) * cnt);
     for (int i = 0; i < cnt; i ++){
         arr[i] = start + i;
     }
     return arr;
 }
#define MAX_RESULT_NUM   10000
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int *) * MAX_RESULT_NUM);
    int size = 0;
    int *columnSizes = malloc(sizeof(int) * MAX_RESULT_NUM);
    for (int i = 1; i < target; i++){
        int cnt = 0;
        if (GetNextNum(i, target, &cnt) == true){
            ans[size] = OutOneArray(i, cnt);
            columnSizes[size] = cnt;
            size++;
        }
    }
    *returnColumnSizes = columnSizes;
    *returnSize = size;
    return ans;
}
```