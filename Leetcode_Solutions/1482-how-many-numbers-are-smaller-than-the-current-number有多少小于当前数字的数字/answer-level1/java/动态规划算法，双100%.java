```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] input = new int[101];
        for (int item : nums) {
            input[item]++;
        }

        int[] dp = new int[101];
        dp[0] = 0;
        for (int index = 1; index < 101; index++) {
            dp[index] = dp[index - 1] + input[index - 1];
        }
        int[] outPut = new int[nums.length];

        for (int index = 0; index < nums.length; index++) {
            outPut[index] = dp[nums[index]];
        }
        return outPut;
    }
}
```