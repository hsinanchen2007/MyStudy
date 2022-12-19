```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findNext(int* nums, int numsSize, int start)
{
    int j;
    int res = -1; //如果没有找到比自己大的，返回-1
    for (j = start + 1; j < numsSize + start; j++) {
        if (nums[j % numsSize] > nums[start]) {
            res = nums[j % numsSize];
             break;
        }
    }

    return res;
}
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }
    int *res = (int*)malloc(sizeof(int) * numsSize);
    int i;

    for (i = 0; i < numsSize; i++) {
        res[i] = findNext(nums, numsSize, i);
    }
    *returnSize = numsSize;
    return res;
}
```
