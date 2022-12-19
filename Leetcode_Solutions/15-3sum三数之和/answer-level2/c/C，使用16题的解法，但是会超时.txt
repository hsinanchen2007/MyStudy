/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define ROW 50000
#define COL3 3

int cmp(void *x, void *y)
{
    return *(int *)x - *(int *)y;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **arr = NULL;
    int i, L, R, sum;

    if (nums == NULL || numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    arr = (int **)malloc(sizeof(int *) * ROW);
    *returnColumnSizes = (int *)malloc(sizeof(int) * ROW);
    *returnSize = 0;

    for (i = 0; i < ROW; i++) {
        arr[i] = (int *)malloc(sizeof(int) * COL3);
    }    

    for (i = 0; i < numsSize - 1; i++) {
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }       
        L = i + 1;
        R = numsSize - 1;
        
        while (L < R) {
            sum = nums[i] + nums[L] + nums[R];
            if (sum == 0) {
                arr[*returnSize][0] = nums[i];
                arr[*returnSize][1] = nums[L];
                arr[*returnSize][2] = nums[R];
                (*returnColumnSizes)[*returnSize] = 3;
                *returnSize += 1;
                L++;
                while(L < R && nums[L] == nums[L - 1]) {
                    L += 1;
                }
                R--;
                while(L < R && nums[R + 1] == nums[R]) {
                    R -= 1;
                }
            } else if (sum > 0) {
                R -= 1;
                while(L < R && nums[R + 1] == nums[R]) {
                    R -= 1;
                }
            } else {
                L += 1;
                while(L < R && nums[L] == nums[L - 1]) {
                    L += 1;
                }
            }
        }
    }

    return arr;
}