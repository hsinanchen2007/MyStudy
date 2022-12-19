从前往后遍历，发现要找的元素则取最后一个元素进行覆盖

int removeElement(int* nums, int numsSize, int val)
{
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    
    int res = numsSize - 1;
    for (int i = 0; i <= res; i++) {
        if (nums[i] == val) {
            nums[i--] = nums[res--];
        }
    }

    return res + 1;
}