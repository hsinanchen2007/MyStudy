解题思路： 计算其位数，通过位数进行判断，位数为偶数的计数加一。

代码流程：
    int findNumbers(int* nums, int numsSize){
        int i;
        int cnt = 0;
        if (numsSize < 1 || numsSize > 500) {
            return 0;
        }

        for (i = 0; i < numsSize; i++) {
            if (nums[i] == 100000) {
                cnt++;
                continue;
            } else if (nums[i] / 10000 != 0) {
                continue;
            } else if (nums[i] / 1000 != 0) {
                cnt++;
                continue;
            } else if (nums[i] / 100 != 0) {
                continue;
            } else if (nums[i] / 10 != 0) {
                cnt++;
                continue;
            }
        }
        return cnt;
    }