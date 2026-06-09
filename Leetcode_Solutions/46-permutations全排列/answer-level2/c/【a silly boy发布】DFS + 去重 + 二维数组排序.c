![36CF97DF-1DE3-4154-8584-435D7C1B5FFF.jpeg](https://pic.leetcode-cn.com/901fc7e401a5a95ea90dba79ffb3022a07f0f7aeb1a1f6f0de9e45a9fdc348ba-36CF97DF-1DE3-4154-8584-435D7C1B5FFF.jpeg)
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define ARRSYSIZE 3

bool IsSameNums(int* nums, int numsSize, int **returnArray, int *returnSize)
{
    int i;
    int j;
    bool returnValue = true;;
    for (i = 0; i < *returnSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (nums[j] != returnArray[i][j]) {
                returnValue = false;
            } 
        }
        if (returnValue == true) {
            return true;
        }
    }

    return false;
}

void SubFuncDfs(int* nums, int numsSize, int index, int **returnArray, int *returnSize)
{
    int i;
    int tmp;
    bool isSameNums = false;
    //printf("index: %d\n", index);
    if (index == numsSize - 1) {
        isSameNums = IsSameNums(nums, numsSize, returnArray, returnSize);
        //printf("isSameNums: %d\n", isSameNums);
        if (isSameNums == false) {
            for (i = 0; i < numsSize; i++) {
                returnArray[*returnSize][i] = nums[i];
            }
            (*returnSize)++;
        }
        //printf("returnSize: %d\n", *returnSize);
    } else {
        //printf("else: nums[0]: %d, nums[1]: %d, nums[2]: %d\n", nums[0], nums[1], nums[2]);
        for (i = index; i < numsSize; i++) {
            tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
            //printf("for: before: else: nums[0]: %d, nums[1]: %d, nums[2]: %d\n", nums[0], nums[1], nums[2]);
            SubFuncDfs(nums, numsSize, index + 1, returnArray, returnSize);
            
            tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
            //printf("for: after: else: nums[0]: %d, nums[1]: %d, nums[2]: %d\n", nums[0], nums[1], nums[2]);
        }
    }
}

int cmp(const void *a, const void *b) 
{
    int *tmpA = *(int **)a;
    int *tmpB = *(int **)b;
    int i;
    for (i = 0; i < ARRSYSIZE; i++) {
        if (tmpA[i] == tmpB[i]) {
            continue;
        } else {
            return tmpA[i] - tmpB[i];
        }
    }
    return tmpA[0] - tmpB[0];
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        (*returnColumnSizes)[0] = (int *)malloc(1 * sizeof(int));
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }

    int i;
    int sum = 1;
    for (i = numsSize; i > 0; i--) {
        sum = sum * i;
    }
    //printf("sum: %d\n", sum);

    int **returnArray = (int **)malloc(sum * sizeof(int *));
    for (i = 0; i < sum; i++) {
        returnArray[i] = (int *)malloc(numsSize * sizeof(int));
        memset(returnArray[i], 0, numsSize * sizeof(int));
    }
    int index = 0;
    *returnSize = 0;
    SubFuncDfs(nums, numsSize, index, returnArray, returnSize);
    
    //printf("*returnSize: %d\n", *returnSize);
    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    //qsort数组
    qsort(returnArray, *returnSize, sizeof(returnArray[0]), cmp);

    return returnArray;
}
```
