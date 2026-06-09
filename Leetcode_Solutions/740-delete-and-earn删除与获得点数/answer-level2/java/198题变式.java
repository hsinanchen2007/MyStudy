```
class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] points = new int[10001];
        for (int num : nums){
            points[num] += num;
        }
        return rob(points);
    }
    public int rob(int[] nums1) {
        int n = nums1.length;
        if (n == 0) return 0;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++){
            dp[i] = Math.max(((i > 1 ? dp[i-2] : 0) + nums1[i]),(i > 0 ? dp[i-1] : 0));
        }
        return dp[n - 1];
    }
}
```
