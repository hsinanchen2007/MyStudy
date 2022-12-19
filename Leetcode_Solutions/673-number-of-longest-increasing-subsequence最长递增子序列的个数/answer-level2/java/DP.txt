```
class Solution {
    public int findNumberOfLIS(int[] nums) {

        int n = nums.length;

        // corner case
        if (n == 0) {
            return  0;
        }
        int[] dp = new int[n];
        int[] info = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            info[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        info[i] = info[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        info[i] += info[j];
                    }
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
        }

        int max = Arrays.stream(dp).max().getAsInt();
        int count = (int)IntStream.range(max - 1, n).filter(idx -> dp[idx] == max)
        .map(i -> info[i])
        .sum();
        return count;
    }
}
```
space: O(n)
time: O(n ^ 2)