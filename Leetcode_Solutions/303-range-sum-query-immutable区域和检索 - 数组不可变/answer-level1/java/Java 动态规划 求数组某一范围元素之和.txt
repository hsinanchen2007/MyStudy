### 解题思路
第一种实现也是动态规划，不过使用的二维数组，超过内存限制。（二维其实有一半是用不上的，i下标不会大于j下标）
第二种实现依旧动态规划，进行了优化，使用一维数组，当求某一范围的和时，
使用从“起始到结束的所有元素之和” 减去 “起始元素之前所有元素之和” 即可。

### 代码

```java
class NumArray {
    private int[] dp;
    public NumArray(int[] nums) {
        int rows = nums.length;
        dp = new int[rows + 1];

        for (int i = 1; i <= rows; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    public int sumRange(int i, int j) {
        // i下标对应元素是加在dp数组的i + 1位置
        // j下标的元素同理，加在dp数组的j+1位置
        // 因此包含j元素的dp减去不含有i元素的dp即所求元素的和
        // dp[j + 1] - dp[i]
        return dp[j + 1] - dp[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```