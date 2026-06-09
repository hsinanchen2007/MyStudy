### 解题思路
此处撰写解题思路
`dp[i]表示到nums[0...i]能够得到的最优时长，则第i次要么选择dp[i-2]+nums[i]。要么不约，则就是dp[i-1]`
![Snipaste_2020-03-24_23-59-09.png](https://pic.leetcode-cn.com/1efc8a0ec379472c83f64ab1a8131916ecbb7204c4863a1e2ca2fd5fc3ffbc3a-Snipaste_2020-03-24_23-59-09.png)

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        //dp[i]表示nums[0....1]能够得到的最长时间
        //1.本次预约，则上一次不能雨夜。dp[i-2]+nums[i]
        //2.本次不预约。则为上一次的dp值。
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