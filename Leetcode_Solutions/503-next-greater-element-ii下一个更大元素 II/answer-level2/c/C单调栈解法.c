```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *ret = (int *)malloc(sizeof(int)*numsSize);
    int *stk = (int *)malloc(sizeof(int)*2*numsSize);
    int top = -1;
    int index = 0;
    for (index = 0; index < numsSize; index++) {
        ret[index] = -1;
    }

    for(int i = 0; i < 2; i++) {
        for (index = 0; index < numsSize; index++) {
            while(top != -1) {
                if (nums[index] > nums[stk[top]]) {
                    ret[stk[top]] = nums[index];
                    top--;
                } else {
                    break;
                }
            }
            top++;
            stk[top] = index;
        }
    }
    free(stk);
    *returnSize = numsSize;
    return ret;
}
```
