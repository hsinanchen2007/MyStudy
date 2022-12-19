## 思路
```
由于是求子序列连续和，至少需要从头到尾遍历一次，便利的过程中进行累加和。
在累加和的过程中需要注意：
1. 累加和 **sum** 加上当前值之后 是否 比当前还要小，如果是，说明之前的累加和是负值，直接抛弃，累加和 从当值位置重新开始。
2. 由于累加和会一直往后走，然后判断，并不进行保存它遇到的最大累加和，因此需要进行记录一下最大的累加和 **maxValue**。
遍历结束，记录的最大值 **maxValue**就是结果。
```

###  第一种 采用 双数组dp 未经优化 会有很多重复计算

> - **不能完全通过，由于双数组会出现内存溢出**
> - **好处是不用考虑那么多，就是暴力法**

```java
class Solution {
    public int maxSubArray(int[] nums) {
        return dp2(nums);
    }
 // 双数组
    public int dp2(int[] nums){
        int n = nums.length;
        int[][] dp = new int[n][n];
        // base
        dp[0][0] = nums[0];
        int max = dp[0][0];
        for(int i = 1; i < n;i++){
            for(int j = 0; j < i; j++){
                dp[j][i] = Math.max(dp[j][i-1] + nums[i], nums[i]);
                max = Math.max(dp[j][i],max);
            }
        }
        return max;
    }   
}
```

### 第二种 对双数组进行优化 

> - **其实使用一维数组就足够了，因为要求是连续的，即当前数只可能向后找，不会往前看，因此一维数组足够**

```java
class Solution {
    public int maxSubArray(int[] nums) {
        return dp(nums);
    }
	// 使用 一维  DP 数组 优化
    public int dp(int[] nums){
        int n = nums.length;
        int[] dp = new int[n];
        // base
        dp[0] = nums[0];  
        int maxValue = dp[0];
        for(int i = 1; i < n; i++){
            // 状态转移方程
            dp[i] = Math.max(dp[i-1] + nums[i], nums[i]);
            // 记录转移过程中的最大连续值
            maxValue = Math.max(maxValue, dp[i]);
        }
        return maxValue;
    }
}
```

### 第三种 优化过了时间之后

> - **优化过了时间之后，其实还可以优化空间。因为每次计算过之后就不再需要前面的值了，所以没必要还用数组进行保存，用过直接丢掉就好了**

```java
class Solution {
    public int maxSubArray(int[] nums) {
        return traverse(nums);
    }
	//优化一维DP 使用一遍循环 搜最大子序列
    public int traverse(int[] nums){
        int n = nums.length;
        int sum =0; // 用于记录累积和
        int max =nums[0];
        for(int i = 0; i < n; i++){
            sum = Math.max(sum+nums[i], nums[i]);
            max = Math.max(sum , max);
        }
        return max;
    }
}
```

记录自己的思路过程，如有错误，欢迎讨论。