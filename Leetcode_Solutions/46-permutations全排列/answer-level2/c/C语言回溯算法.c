思路：
(1) 通过used数组标记nums中某个元素是否已经被使用了，如果已经被使用了，则不能再使用，否则将该元素放到临时结果数组arr中，并将used数组的对应位标记为1。
(2) 如果临时结果数组arr的索引index已经达到numsSize-1，即已经找到了numsSize个元素，则将当前的临时结果数组arr加入到res中。
(3) 如果临时数组arr的索引index还没到numsSize - 1，说明还需要继续找未被使用的元素，则进入下一层递归，在剩下的未被使用的nums元素中寻找未被使用的元素。
(4) 当前层的递归结束返回之前，需要将used数组中，当前元素对应的位清成0，即标记为未被使用。

代码：
void AddToRes(int **res, int *resIndex, int *arr, int size)
{
    int i;

    *(res + *resIndex) = (int *)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        *(*(res + *resIndex) + i) = arr[i];
    }
    (*resIndex)++;

    return;
}

void BackTrace(int *nums, int *used, int numsSize, int *arr, int index, int **res, int *resIndex)
{
    int i;

    for (i = 0; i < numsSize; i++) {
        if (used[i] == 1) {
            continue;
        }

        arr[index] = nums[i];
        used[i] = 1;

        if (index + 1 == numsSize) {
            AddToRes(res, resIndex, arr, index + 1);
        } else {
            BackTrace(nums, used, numsSize, arr, index+1, res, resIndex);
        }
        
        used[i] = 0;
    }

    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res = NULL;
    int *used = NULL;
    int *tmpArray = NULL;
    int i;
    int *sizes = NULL;
    int total = 1;

    *returnSize = 0;
    if (numsSize <= 0) {
        return NULL;
    }

    for (i = 1; i <= numsSize; i++) {
        total *= i;
    }

    res = (int **)malloc(sizeof(int *) * total);
    memset(res, 0, sizeof(int *) * total);

    sizes = (int *)malloc(sizeof(int) * total);
    for (i = 0; i < total; i++) {
        sizes[i] = numsSize;
    }
    *returnColumnSizes = sizes;

    used = (int *)malloc(sizeof(int) * numsSize);
    memset(used, 0, sizeof(int) * numsSize);

    tmpArray = (int *)malloc(sizeof(int) * numsSize);

    BackTrace(nums, used, numsSize, tmpArray, 0, res, returnSize);

    free(used);
    free(tmpArray);

    return res;
}