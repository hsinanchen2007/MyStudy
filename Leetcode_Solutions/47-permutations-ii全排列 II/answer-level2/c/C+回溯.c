### 解题思路
回溯算法。注意剪枝条件

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int** res;
int resLen;
static int* marked;
int min;
int max;

void print_arr(int* tmp, int tmpLen)
{
    for (int i = 0; i < tmpLen; i++) {
        printf("%d ",tmp[i]);
    }
    printf("\n");
}

int compare(const void* a, const void* b)
{
    return (*(int*)a > *(int*)b);
}

void createMarked(int* nums, int numsSize)
{   
    min = INT_MAX;
    max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        min = fmin(min, nums[i]);
        max = fmax(max, nums[i]);
    }
    int markedLen = max - min + 1;
    marked = (int*)malloc(markedLen*sizeof(int));
    memset(marked, 0, markedLen*sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        marked[nums[i] - min]++;
    }
}

void backtrack(int* nums, int numsSize, int* tmp, int tmpLen)
{
    if (tmpLen == numsSize) {
        memcpy(res[resLen], tmp, numsSize*sizeof(int));
        resLen++;
        return ;
    }
    for (int i = 0; i < numsSize; i++) {
        if (marked[nums[i] - min] == 0) {
            continue;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        tmp[tmpLen] = nums[i];
        tmpLen++;
        marked[nums[i] - min]--;
        backtrack(nums, numsSize, tmp, tmpLen);
        //回溯
        marked[nums[i] - min]++;
        tmp[tmpLen-1] = 0;
        tmpLen--; 
    }
    return ;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    res = (int**)malloc(700*sizeof(int*));
    for (int i = 0; i < 700; i++) {
        res[i] = (int*)malloc(numsSize*sizeof(int));
    }
    resLen = 0;
    createMarked(nums, numsSize);
    int* tmp = (int*)malloc(numsSize*sizeof(int));
    memset(tmp, 0, numsSize*sizeof(int));
    
    qsort(nums, numsSize, sizeof(int), compare);
    backtrack(nums, numsSize, tmp, 0);
    *returnSize = resLen;
    *returnColumnSizes = (int*)malloc(resLen*sizeof(int));
    for (int i = 0; i < resLen; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return res;
}
```