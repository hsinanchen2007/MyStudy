### 解题思路
此处撰写解题思路

### 代码

```c
void backTrace(int index, int *nums, int numsSize, int **res, int *temp, int *tempSize, int** returnColumnSizes, int *resIndex)
{
    if (index == numsSize){
        return;
    }
    for (int i = index; i < numsSize; i++){
        temp[*tempSize] = nums[i];
        *tempSize = *tempSize + 1;
        memcpy(res[*resIndex], temp, (*tempSize) * sizeof(int));
        (*returnColumnSizes)[*resIndex] = *tempSize;
        *resIndex = *resIndex + 1;
        backTrace(i + 1, nums, numsSize, res, temp, tempSize, returnColumnSizes, resIndex);
        *tempSize = *tempSize - 1;
    }
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int resNum = 1 << numsSize;
    *returnSize = resNum;
    int **res = (int**)malloc(sizeof(int*) * resNum);
    *returnColumnSizes = (int*)calloc(1, sizeof(int) * resNum);
    if (res == NULL){
        return NULL;
    }
    for (int i = 0; i < resNum; i++){
        res[i] = (int*)malloc(sizeof(int) * numsSize);
        if(res[i] == NULL){
            return NULL;
        }
        memset(res[i], 0, sizeof(int) * numsSize);
    }
    int *temp = (int*)malloc(sizeof(int) * numsSize);
    if(temp == NULL){
        return NULL;
    }
    memset(temp, 0, sizeof(int) * numsSize);
    int tempSize = 0;
    int resIndex = 0;
    backTrace(0, nums, numsSize, res, temp, &tempSize, returnColumnSizes, &resIndex);

    return res;
}
```