

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int product = 1;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        product *= nums[i];
        while (product >= k && left <= i) {
            product /= nums[left];
            left++;
        }
        sum += i - left + 1;
    }
    return sum;
}