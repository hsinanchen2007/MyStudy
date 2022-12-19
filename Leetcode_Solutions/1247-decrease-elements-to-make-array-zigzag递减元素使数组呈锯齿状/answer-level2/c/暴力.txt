执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.7 MB
, 在所有 C 提交中击败了
100.00%
的用户


int movesToMakeZigzag(int* nums, int numsSize){
    if (nums == NULL || numsSize == 1) {
        return 0;
    }

    if (numsSize == 2) {
        if (nums[0] != nums[1]) {
            return 0;
        } else {
            return 1;
        }
    }

    int *temp = (int *)malloc(sizeof(int) * numsSize);
    memset(temp, 0, sizeof(int) * numsSize);
    memcpy(temp, nums, sizeof(int) * numsSize);

    int oddTimes = 0;
    int evenTimes = 0;
    int i;

    // 计算生成奇数锯齿的次数
    for (i = 1; i < numsSize; i = i + 2) 
    {
        if (nums[i] <= nums[i - 1]) {
            oddTimes += (nums[i - 1] - nums[i] + 1);
            nums[i - 1] = nums[i] - 1;
        }

        if ((i + 1 < numsSize) && (nums[i] <= nums[i + 1])) {
            oddTimes += (nums[i + 1] - nums[i] + 1);
            nums[i + 1] = nums[i] - 1;
        }

    }

    printf("oddtime = %d ", oddTimes);

    // 计算生成偶数锯齿的次数
    for (i = 0; i < numsSize; i = i + 2) 
    {
        if ((i + 1 < numsSize) && (temp[i] <= temp[i + 1])) {
            evenTimes += (temp[i + 1] - temp[i] + 1);
            temp[i + 1] = temp[i] - 1;
        }

        if ((i - 1 >= 0) && (temp[i] <= temp[i - 1])) {
            evenTimes += (temp[i - 1] - temp[i] + 1);
            temp[i - 1] = temp[i] - 1;
        }

    }

    free(temp);
    printf("eventime = %d ", evenTimes);

    return oddTimes > evenTimes ? evenTimes : oddTimes;

}