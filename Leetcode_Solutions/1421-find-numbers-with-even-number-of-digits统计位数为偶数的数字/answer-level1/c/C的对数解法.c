int findNumbers(int *nums, int numsSize)
{
    int i, count = 0, digit;
    for (i = 0; i < numsSize; i++) {
        digit = floor(log10(nums[i]) + 1);
        if(digit & 0x1) {
            continue;
        }
        count++;
    }
    return count;
}