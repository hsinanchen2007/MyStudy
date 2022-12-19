### 解题思路
动态规划，开始想的是建立二维数组dp[i][j] = dp[i][j-1] + nums[j]，写一个二重循环，然后就可以求出所有的情况。但是提交的时候测试第十五个测试用例的时候出现超时。
于是想了一下换一种写法:dp[i]表示前i项和，不包括i项。
nums = [-2, 0, 3, -5, 2, -1], i = 1, j = 3
表示： 0 + 3 - 5 = dp[4] - dp[1]。提交了一下成功了。
执行用时 :12 ms, 在所有 Java 提交中击败了99.61%的用户
内存消耗 :40.2 MB, 在所有 Java 提交中击败了98.70%的用户

### 代码

```java
class NumArray {
    private int[] dp;

    public NumArray(int[] nums) {
        dp = new int[nums.length+1];
        dp[0] = 0;

        for(int i = 1; i < dp.length; i++){
            dp[i] = dp[i-1] + nums[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```