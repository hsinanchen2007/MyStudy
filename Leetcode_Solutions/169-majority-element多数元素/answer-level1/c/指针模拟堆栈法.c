int majorityElement(int* nums, int numsSize){
    int *result = calloc(sizeof(int), numsSize);
    int *top = result;
    for (int i = 0; i < numsSize; i++) {
        if (top == result) {
            *result = nums[i];
            result++;
            continue;
        }
        if (*top == nums[i]) {
            *result = nums[i];
            result++;
        } else {
            result--;
        }
    }
    return *top;
}