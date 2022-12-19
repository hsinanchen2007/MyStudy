```c
// 交换两个 int
void swap(int *a, int *b) {
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

int firstMissingPositive(int* nums, int numsSize){
    int i = 0;
    int num;
    // 循环遍历 nums 中的元素
    while (i < numsSize) {
        // 第 i 个元素的值
        num = nums[i];
        // 长度为 numsSize 的数组，第一个正数不会超过 numsSize + 1
        // 因此只需要关心 [1, numsSize] 范围內的元素
        if (num > 0 && num <= numsSize) {
            // 与本应所在位置的数相同时，不做处理
            if (nums[i] == nums[num - 1]) {
                i++;
                continue;
            }
            // 位置不对，换到它该去的位置
            if (num - 1 != i)
                swap(&nums[i], &nums[num - 1]);
        }
        // 查看交换后的元素，如果超出范围或已是正确的位置，跳到下个位置
        num = nums[i];
        // 此处 num - 1 == i 要放在最后，因为 num 可能等于 INT_MIN
        if (num <= 0 || num > numsSize || num - 1 == i)
            i++;
    }

    // 找出第一个位置不对的元素
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] - 1 != i)
            return i + 1;
    }
    return numsSize + 1;
}
```