### 解题思路
用一个长度为n的数组dp[]，dp[i]为前i项和。区间(i,j)的和就是dp[j] - dp[i-1] 。

### 代码

```java
class NumArray {

    private int[] dp;

    public NumArray(int[] nums) {
        int n = nums.length;
        this.dp = new int[n+1];
        for (int i = 0; i < n; i++) {
            dp[i+1] = dp[i] + nums[i];
        }
    }

    public int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```