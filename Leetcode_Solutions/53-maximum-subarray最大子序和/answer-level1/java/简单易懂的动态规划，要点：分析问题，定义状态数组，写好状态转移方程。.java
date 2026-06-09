**解法一：暴力解**

通过遍历该数组所有的连续子数组，以求得最大和。

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int ans = nums[0];
        int sum;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                ans = Math.max(ans, sum); 
            }
        }
        return ans;
    }
}
```

**复杂度分析** 

- 时间复杂度：O(N^2)。
- 空间复杂度：O(1)。

**解法二：动态规划**

使用dp[i]表示以索引i结尾的最大和的连续子数组的和，得出状态转移方程：

dp[i] = Math.max(nums[i], dp[i-1] + nums[i])

其中含义为若当前索引i加入i-1为结尾的子数组，能够比当前一个元素nums[i]的子数组的和要大，就将索引i加入子数组，成为子数组的一部分，否者就自己成立一个子数组，当前子数组元素只有nums[i]，记录最大的dp[i], 即为答案。

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;	// 由于数组nums长度不为0，所以没有考虑n为零的情况。
        int[] dp = new int[n];	// 定义状态数组
        int ans = nums[0];		// 初始化最大值
        dp[0] = nums[0];		// 初始化状态
        for(int i = 1; i < n; i++){
            dp[i] = Math.max(nums[i], dp[i-1] + nums[i]);	// 根据状态转移方程更新数组
            ans = Math.max(ans, dp[i]); 
        }
        return ans;
    }
}
```

**复杂度分析** 

- 时间复杂度：O(N)。
- 空间复杂度：O(N)。

**解法三：优化空间复杂度的动态规划**

可以从上述状态转移方程得知，获得下一个状态时只需要知道上一个状态就好，所以我们完全可以用一个变量表示状态，而不是用一个数组。

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int sum = nums[0];	// 用sum保存状态
        int ans = nums[0];
        for(int i = 1; i < n; i++){
            sum = Math.max(nums[i], sum + nums[i]);
            ans = Math.max(ans, sum); 
        }
        return ans;
    }
}
```

**复杂度分析** 

- 时间复杂度：O(N)。
- 空间复杂度：O(1)。

