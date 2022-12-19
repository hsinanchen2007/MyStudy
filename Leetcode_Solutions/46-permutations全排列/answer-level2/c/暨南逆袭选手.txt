### 解题思路
处理指针真的是让人头疼
典型的回溯算法，细节有点磨人

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int swap(int *nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    return 0;
}

void backTrack(int *nums,int numsSize, int startIndex, int **retArray, int *returnSize){
    if(startIndex == numsSize ) {
        for(int i = 0; i < numsSize; i++){
            retArray[*returnSize][i] = nums[i];
        }
        (*returnSize)++;
        return;
    }
    for(int i = startIndex; i < numsSize; i++ ){
        swap(nums, startIndex, i);
        backTrack(nums, numsSize, startIndex+1, retArray,returnSize);
        swap(nums, startIndex, i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(numsSize == 0) return 0;
    // int comAll = computeAll(numsSize);
    int comAll = 1, k = 1;
    while(k <= numsSize) {
        comAll *=k;
        k++;
    }
    int **retArray = (int **) malloc (sizeof(int*) * comAll);
    *returnColumnSizes = (int *) malloc (sizeof(int) * comAll);
    for( int i = 0; i < comAll; i++){
        retArray[i] = (int *) malloc (sizeof(int) * numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }
    backTrack(nums, numsSize, 0, retArray, returnSize);
    return retArray;
}
```