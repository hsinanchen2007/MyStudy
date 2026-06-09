滑动窗口：左边窗口从小到大遍历，右边窗口从大到小遍历
剪枝：
1、提前先算好最大和，遍历窗口右侧时，每次最后减去当前值，即为下次要check的值。
2、遇到符合条件的直接break即是最长的

int maxSubArrayLen(int *nums, int numsSize, int k)
{
    
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        int flag = 0;
        if (numsSize - i < max) {
            continue;
        }
        for (int k = i; k < numsSize; k++) {
            sum += nums[k];
        }
        for (int j = numsSize - 1; j >= i; j--) {
            if (sum == k) {
                if (max < j - i + 1) {
                    max = j - i + 1;
                    break;
                }
            }
            sum -= nums[j];
        }
    }
    return max;
}
