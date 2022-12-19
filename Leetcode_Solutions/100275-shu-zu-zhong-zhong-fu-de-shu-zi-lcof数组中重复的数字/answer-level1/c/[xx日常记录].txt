官方解题

数据放的一定有重复
所以必然有nums[i] == nums[nums[i]] 的可能性，既
类似  31230  这种可能  找到就好。 

int findRepeatNumber(int* nums, int numsSize){

    int i;
    for (i = 0; i < numsSize; ++i) {
        while(nums[i] != i) {
            if(nums[i] == nums[nums[i]]) {
                return nums[i];
            }
            int tmp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = tmp;
        }
    }
    return 0;
} 

自己偏向哈希


