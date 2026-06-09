### 方法一：递归+记忆化搜索

- 单独递归---超时
- 递归 + 记忆化搜索     （自顶向下）

```java
class Solution {
    int[] memory;
    public int numSquares(int n) {
        memory = new int[n + 1];
        for(int i=0;i<=n;i++){
            // 初始为最大值,这样后边才能比较最小值
            memory[i] = Integer.MAX_VALUE;
        }
        return count(n);
    }
    public int count(int n){
        // 说明上一个递归传下来的 n - i*i = 0 说明n就是一个完全平方数
        if(n == 0) return 0; 

        // 记忆化的核心
        if(memory[n] !=  Integer.MAX_VALUE) 
            return memory[n]; //memory[n]不是初始值,直接返回之前计算好的
        
		// 找memory[n]最小的情况：
        // 当前memory[n]就是最小，或者通过之前计算的memory[n-i*i] + 1(完全平方数i*i)得到
        for(int i=1;i*i <= n;i++){
            // 找到最小值,状态转移方程
            memory[n] = Math.min(memory[n], 1 + count(n-i*i));
        }
        return memory[n];
    }
}
```

### 方法二：动态规划

- 记忆化搜索（自顶向下）----> 动态规划（自底向上）
- 如果`n`为`0`，则结果为`0`
- 初始化长度为`n+1`的数组`dp`，每个位置都为`0`
- 对数组进行遍历，下标为`i`，**每次都将当前数字先更新为最大的结果**，即`dp[i]=i`，比如`i=4`，**最坏结果**为`4=1+1+1+1`即为`4`个数字
- `状态转移方程：dp[i] = Math.min(dp[i],1+dp[i- j*j])`  ,`i`表示当前数字，`j*j`表示一个平方数
- 时间复杂度：$ O(n\sqrt n)$
- 空间复杂度：O(n)

```java
class Solution {
    public int numSquares(int n) {
        // dp[i] 为正整数i的最小分割
        int[] dp = new int[n + 1];
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            //dp[i] = Integer.MAX_VALUE; // 初始化为极大值
            dp[i] = i;
            for(int j=1;j*j <= i;j++){
                // 状态转移方程
               dp[i] = Math.min(dp[i],1+dp[i- j*j]);
            }
        }
        return dp[n];
    }
}
```