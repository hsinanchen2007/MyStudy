```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 3) {
        returnColumnSizes = NULL;
        return NULL;
    }
    int **ret = (int **)malloc(sizeof(int*) * numsSize * numsSize);
    int **Ret = (int **)malloc(sizeof(int*) * numsSize * numsSize);
    ret[*returnSize] = (int *)malloc(sizeof(int) * 3);
    *returnColumnSizes = malloc(sizeof(int) * numsSize * numsSize);
    qsort(nums, numsSize, sizeof(int), compare);
    int i;
    int low;
    int high;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] > 0) {
            break;
        }
        low = i + 1;
        high = numsSize - 1;
        while(low < high) {
            if (nums[i] + nums[low] + nums[high] == 0) {
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[low];
                ret[*returnSize][2] = nums[high];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                ret[*returnSize] = (int *)malloc(sizeof(int) * 3);
                int j;
                for(j = low; j < high; j++) {
                    if (nums[j] != nums[j + 1]) {
                        break;
                    }
                }
                low = j + 1; //低位去重
                for(j = high; j >low; j--) {
                    if (nums[j] != nums[j - 1]) {
                        break;
                    }
                }
                high = j - 1;//高位去重
            } else if (nums[i] + nums[low] + nums[high] < 0) {
                low++;
            } else {
                high--;
            }
        } 
        int k;
        for(k = i; k < low - 1; k++) {
            if (nums[k] != nums[k + 1]) {
                break;
            }
        }
        i = k;//当前位置去重
    }
    /*
    int *repeat = (int *)malloc(sizeof(int) * (*returnSize));
    memset(repeat, 0, *returnSize);

    for (i = 0; i < *returnSize; i++) {
        for (int j = i + 1; j < *returnSize; j++) {
            if (ret[i][0] == ret[j][0] && ret[i][1] == ret[j][1] && ret[i][2] == ret[j][2]) {
                repeat[j] = 1;
            }
        }
    }

    int count = 0;
    for (i = 0; i < *returnSize; i++) {
        if (repeat[i] != 1) {
            Ret[count] = (int *)malloc(sizeof(int) * 3);
            memcpy(Ret[count], ret[i], sizeof(int) * 3);
            count++;
        }
    }
    *returnSize = count;
    free(ret);
    return Ret;
    */
    // 常规遍历去重超时
    return ret;
    
}
```
