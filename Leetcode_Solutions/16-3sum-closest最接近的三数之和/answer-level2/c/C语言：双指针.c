
```c
int cmp(const void* a, const void* b){
    return *(int*)a > *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    if (numsSize == 3)
        return nums[0] + nums[1] + nums[2];

    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int res = 0;
    int maxGap = INT_MAX;

    for (int i = 0; i < numsSize - 2; i++){
        //skip repeating numbers.
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = numsSize - 1;

        while (j < k){
            int num = nums[i] + nums[j] + nums[k];
            if (num == target)
                return target;
            else {
                //find the nearest sum.
                int gap = abs(num - target);
                if (gap < maxGap){
                    maxGap = gap;
                    res = num;
                }
                if (num < target){
                    //skip repeating numbers.
                    while (j < numsSize - 1 && nums[j] == nums[j + 1])
                        j++;
                    j++;
                }
                else {
                    //skip repeating numbers
                    while (k > 0 && nums[k] == nums[k - 1])
                        k--;
                    k--;
                }
            }
        }
    }
    return res;
}


```