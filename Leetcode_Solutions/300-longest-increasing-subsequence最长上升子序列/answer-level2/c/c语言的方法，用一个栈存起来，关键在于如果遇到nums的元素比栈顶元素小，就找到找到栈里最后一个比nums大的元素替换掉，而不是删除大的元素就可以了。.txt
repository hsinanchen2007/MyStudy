

int lengthOfLIS(int* nums, int numsSize){
    if (numsSize <= 0) {
        return 0;
    }
    if (numsSize == 1) {
        return 1;
    }
    int stack[10240] = {0};
    int start = 0; 
    int end = 0;
    int max = 0;
    stack[end] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (stack[end] < nums[i]) {
            stack[++end] = nums[i];
        }
        else {
            int tmp = end;
            while (tmp >= 0 && stack[tmp] >= nums[i]) {
                tmp--;
            }
            stack[++tmp] = nums[i];
        }
    }
    return end + 1;
}