
用最土的办法，暴力循环竟然解了^_^，不过时间有些悬。
```
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){

    int *ret = malloc(sizeof(int)*numsSize);
    memset(ret,-1,sizeof(int)*numsSize);
    *returnSize = numsSize;

    int i;
    int j;
    for (i=0;i<numsSize;i++) {
        for(j = i+1; j < i+numsSize; j++)  {
            if(nums[j%numsSize] > nums[i]) {
                ret[i] = nums[j%numsSize];
                break;
            }
        }
    }

    return ret;
}
```
