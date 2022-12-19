**方法一：动态规划**
```
class Solution {
    /**
    * 思路：
    * (1) 创建dp数组，存储每个预约位置符合要求的最长预约时间。
    * (2) 预约序列中只有一个预约时，最长时间就是这个预约的时长；
    *   如果有两个预约，则预约最长时间为这两个预约中时长较长的。
    * (3) 从第三个预约开始遍历预约序列，每个预约位置符合要求的最长预约时间为，
    *   在上一位得到的最长预约时间或者前一位得到的最长预约时间加当前预约时长中较长的。
    * (4) 遍历完成后返回再最后一位预约位置能得到的最长预约时间。
    */
    public int massage(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
}
```

**方法二：动态规划优化空间**
```
class Solution {
    /**
    * 思路：
    * 由题根据每个预约位置能得到的最长预约时间规则与前两位预约位置的关系，
    *   遍历预约序列，每次根据前两位得到当前位置的最长预约时间。
    */
    public int massage(int[] nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.length; i++) {
            int c = Math.max(b, a + nums[i]);
            a = b;
            b = c;
        }
        return b;
    }
}
```
