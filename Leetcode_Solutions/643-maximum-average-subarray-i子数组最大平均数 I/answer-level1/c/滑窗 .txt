double findMaxAverage(int* nums, int numsSize, int k){
    int idx;
    int subMax = nums[0];
    for (idx = 1; idx < k; idx++) {
        subMax += nums[idx];
    }

    int gMax = subMax;
    for (idx = 1; idx <= numsSize - 1 - (k - 1); idx++) {
        subMax = subMax - nums[idx - 1] + nums[idx + k - 1];
        if (subMax > gMax) {
            gMax = subMax;
        }
    }

    return (double)gMax / k;
}