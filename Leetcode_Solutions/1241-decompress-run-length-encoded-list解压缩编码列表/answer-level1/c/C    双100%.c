所有nums[2Ii] 和为返回长度


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int i;
    *returnSize = 0;
    for(i = 0; i < numsSize/2; i++){
        *returnSize += nums[2*i];
    }

    int *retrunList = (int *)malloc(*returnSize * sizeof(int));
    int *p = retrunList;
    for(i = 0; i < numsSize/2; i++){
        while(nums[2*i]--){
            *(p++) = nums[2*i + 1];
        }
    }
    return retrunList;
}