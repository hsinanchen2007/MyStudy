```
int comp(const void *a,const void *b) {
    return *(int*)a - *(int*)b;
}
    
int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), comp);
    int min = INT_MAX;
    for (int i = 0;i < numsSize;i++) {
        int j = i + 1;
        int k = numsSize - 1;
        int curMin = INT_MAX;
        int subTarget = target - nums[i];
        while(j < k) {
            int sum = nums[j] + nums[k];
            if (abs(curMin) > abs(sum - subTarget)) {
                curMin = sum - subTarget;
                //printf("");
            }
            if (sum > subTarget) {
                k--;
            } else if (sum < subTarget) {
                j++;
            } else {
                return target;
            }
        }
        if (abs(curMin) < abs(min)) {
            min = curMin;
        }
    }
    return target + min;
}

```
