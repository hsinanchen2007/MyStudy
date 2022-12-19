### 解题思路
注意需要去重

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b;
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int maxRet = numsSize;
    int **ret = (int**)malloc(maxRet * sizeof(int*));
    
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2 && nums[i] <= 0; i++) {
        if (i && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = numsSize - 1;
        while (k > j) {
            int tmp = nums[i] + nums[j] + nums[k];
            if (0 == tmp) {
                if (maxRet == *returnSize) {
                    maxRet *=2;
                    ret = (int**)realloc(ret, maxRet * sizeof(int*));
                }

                ret[*returnSize] = (int*)malloc(sizeof(int) * 0x3);
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[j];
                ret[*returnSize][2] = nums[k];
                (*returnSize)++;
                
                tmp = nums[j];
                while (j < k && nums[j] == tmp) {
                    j++;
                }
                tmp = nums[k];
                while (j < k && nums[k] == tmp) {
                    k--;
                }
            } else if (tmp > 0) {
                k--;
            } else {
                j++;
            }
        }
    }

    *returnColumnSizes =  (int*)calloc(sizeof(int), *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return ret;
}
```