int maxSubArray(int* nums, int numsSize){
    int idx;
    int globalmax = nums[0]; // 全局最大和
    int tempmax = nums[0]; // 临时最大和
    int sum = nums[0];

    for (idx = 1; idx < numsSize; idx++) {
        if (tempmax < 0) {  // 如果临时的最大和小于零，则不论当前元素是否大于零，当前元素都将是临时最大和
            tempmax = nums[idx];
            if (tempmax > globalmax) {
                globalmax = tempmax;
            }
        } else { // 如果临时最大和大于零，则临时最大和加上当前元素
             tempmax += nums[idx];
            if (tempmax > globalmax) {
                globalmax = tempmax;
            }
        }

    }

    return globalmax;
}