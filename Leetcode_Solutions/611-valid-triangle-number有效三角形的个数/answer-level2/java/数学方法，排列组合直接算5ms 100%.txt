![捕获.PNG](https://pic.leetcode-cn.com/c257fe1888d06b824524af2a37f86bd85d8c26ffb0d2908c304ccb79f70c503d-%E6%8D%95%E8%8E%B7.PNG)


```
public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int maxValue = nums[nums.length-1];
        int[] record = new int[maxValue+1];
        int sortedLen = 0;
        int[] sortedNums = new int[nums.length];
        // record number and store every number unique
        for (int i = 0;i < nums.length;i++) {
            record[nums[i]]++;
            if (nums[i] > 0 && record[nums[i]] == 1) {
                sortedNums[sortedLen++] = nums[i];
            }
        }
        // we pass 0 number
        record[0] = 0;
        // calculate dp[i] = sum (nums <= i);
        int[] dp = new int[maxValue+1];
        for (int i = 1;i <= maxValue;i++) {
            dp[i] = dp[i-1] + record[i];
        }

        // calculate combination, 4 kinds of combine
        int sum = 0;
        for (int i = 0;i < sortedLen;i++) {
            int number1 = sortedNums[i];
            int nums_1 = record[number1];
            // three same number1(1, 1, 1)
            if (nums_1 > 2) {
                sum += (nums_1 * (nums_1 - 1) * (nums_1 - 2)) / 6;
            }
            // two same number1(1, 1, 2)
            if (record[number1] > 1) {
                sum += (((record[number1] * (record[number1] - 1)) / 2) * (dp[Math.min(maxValue, 2 * number1 - 1)] - dp[number1]));
            }
            for (int j = i+1;j < sortedLen;j++) {
                int number2 = sortedNums[j];
                // two same number2(1,2,2)
                if (record[number2] > 1) {
                    sum += (record[number1] * ((record[number2] * (record[number2] - 1)) / 2));
                } else if (j == sortedLen - 1) {
                    break;
                }
                int sum2 = number1 + number2;
                // three differect number (1,2,3)
                sum += (record[number1] * record[number2] * (dp[Math.min(maxValue, sum2-1)] - dp[number2]));
            }
        }
        return sum;
    }
```
