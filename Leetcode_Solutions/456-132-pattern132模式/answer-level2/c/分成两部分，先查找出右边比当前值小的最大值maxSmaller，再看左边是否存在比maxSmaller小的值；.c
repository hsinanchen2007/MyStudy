bool findMaxsmaller(int *nums, int numsSize, int startid, int big, int *maxSmaller)
{
    int tmp = -2147483648;
    int i;
    for (i = startid; i < numsSize; i++) {
        if (nums[i] < big) {
            tmp = tmp < nums[i]?nums[i]:tmp;
        }
    }
    *maxSmaller = tmp;
    if (tmp == -2147483648) {
        return false;
    }
    return true;
}
bool findsmall(int *nums, int endid, int maxSmaller)
{
    int i;
    for (i = 0; i <= endid; i++) {
        if (nums[i] < maxSmaller) {
            return true;
        }
    }
    return false;

}
bool find132pattern(int* nums, int numsSize){
    int i;
    int maxSmaller;
    bool result = true;
    for (i = 1; i < numsSize - 1; i++) {
        result = findMaxsmaller(nums, numsSize, i + 1, nums[i], &maxSmaller);
        if (result) {
            result = findsmall(nums, i - 1, maxSmaller);
            if (result) {
                return true;
            }
        }
        
    }
    return false;
    }