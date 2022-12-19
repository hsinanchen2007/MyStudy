void Change(int *a, int *b)
{
    int change;
    change = *a;
    *a = *b;
    *b = change;
}
void sortColors(int *nums, int numsSize)
{
    int i;
    int left = 0;
    int right = numsSize - 1;
    if (numsSize <= 1) {
        return;
    }
    for (i = 0; i <= right; i++) {
        if (nums[i] == 0) {
            Change(nums + left, nums + i); // 0肯定在左边
            left++;
        } else if (nums[i] == 2) {
            Change(nums + right, nums + i); // 2肯定在右边
            right--;
            i--; // 注意右边的值还没进行处理，需要处理
        }
    }
}