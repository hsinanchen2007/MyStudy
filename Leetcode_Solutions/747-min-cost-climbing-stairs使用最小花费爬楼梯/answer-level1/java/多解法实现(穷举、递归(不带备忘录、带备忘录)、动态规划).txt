这是一道典型的动态规划题目。动态规划的题目大多可以通过穷举和递归实现，但是由于递归会出现子问题重复，所以递归的复杂度一般是O(2^n)。这时，我们可以想到使用“备忘录”的方式把出现过的子问题记录下来，待到再次遇到重复的子问题时，不用重复计算。具体可参考斐波那契数列的解法。递归和动态规划都需要一个状态转移方程以及BaseCase(可以理解为递归的出口，比如斐波那契的 if (n == 1 || n == 2) return 1;),递归是自顶向下寻找答案，而动态规划则是自底向上迭代出最佳解。

下面是这道题的穷举解法。(超时)
```
class Solution {
    private int ans = Integer.MAX_VALUE;
    
    public int minCostClimbingStairs(int[] cost) {
        //从第一个阶梯开始爬
        exhaustion(cost, 0, 0);
        //从第二个阶梯开始爬
        exhaustion(cost, 1, 0);
        return ans;
    }
    
    private void exhaustion(int[] arr, int cur, int cost) {
        //走到了阶梯顶
        if (cur >= arr.length) {
            ans = Math.min(ans, cost);
            return;
        }
        //cost：走到这道阶梯花费的体力
        cost += arr[cur];
        //可选择走一个阶梯或者两个阶梯
        exhaustion(arr, cur + 1, cost);
        exhaustion(arr, cur + 2, cost);
    }
}
```
列出状态转移方程：
```
OPT(i) = min(OPT(i - 1), OPT(i - 2)) + cost[i] 
BASECASE:
OPT(0) = cost[0]
OPT(1) = cost[1]
```
第n个阶梯可以是第n-1的阶梯选择前进一个阶梯到达，或者第n-2的阶梯选择前进两个阶梯到达，只要选择其中消耗体力最少的再加上当前阶梯消耗的体力，那么可以保证当前阶梯消耗的体力是最佳解。其中 i == 0 和 i == 1 是基本情况，即可选择从阶梯1开始爬(i == 0)或从阶梯2开始爬(i == 1)。

实现递归解法(包括不带"备忘录"和带"备忘录"两种解法):

解法一：不带"备忘录"(超时)
```
class Solution {
   
    public int minCostClimbingStairs(int[] cost) {
        return recursion(cost, cost.length);
    }
    
    
    private int recursion(int[] arr, int cur) {
        //递归的出口，此时若是到了第一个阶梯或者第二个阶梯，直接返回要消耗的体力
        if (cur == 0 || cur == 1)
            return arr[cur];
        //状态转移方程 -> OPT(i) = min(OPT(i - 1), OPT(i - 2)) + arr[i];
        //注意这里是从阶梯顶自下寻找最佳解，所以cur是从arr.length开始进行递归寻解
        int min = Math.min(recursion(arr, cur - 1), recursion(arr, cur - 2)) 
            + (cur == arr.length ? 0 : arr[cur]);
        
        return min;
    }
}
```
 解法二：带"备忘录"(通过)：

因为会出现子问题重复计算，时间复杂度太高导致超时。下面是子问题出现的情况：
![DCIM.jpg](https://pic.leetcode-cn.com/c9c95142818f3ca0add25f4f8a8a2dc35c66e6c1430f46ef8302177d2e8a28d7-DCIM.jpg)
既然有重复子问题存在，那么我们可以使用一个数组把已经遇到的子问题的解保存起来，待到再次遇到相同的子问题时，直接返回即可，无需进行重复的计算。
```
class Solution {
    
    public int minCostClimbingStairs(int[] cost) {
        return recursion(cost, cost.length, new int[cost.length + 1]);
    }
    

    //flag数组充当了"备忘录"的作用，把已经解决过的子问题的解保存起来，以后再遇到重复的子问题时不用进行重复的计          算。
    private int recursion(int[] arr, int cur, int[] flag) {
        //递归的出口，此时若是到了第一个阶梯或者第二个阶梯，直接返回要消耗的体力
        if (cur == 0 || cur == 1)
            return arr[cur];
        if (flag[cur] != 0)
            return flag[cur];
        //状态转移方程 -> OPT(i) = min(OPT(i - 1), OPT(i - 2)) + arr[i];
        //注意这里是从阶梯顶自下寻找最佳解，所以cur是从arr.length开始进行递归寻解
        int min = Math.min(recursion(arr, cur - 1, flag), recursion(arr, cur - 2, flag)) 
            + (cur == arr.length ? 0 : arr[cur]);
        flag[cur] = min;
        return min;
    }
}
```
重头戏来了，下面给出动态规划解法：

上面说过递归是自顶向下寻找答案，而动态规划是自底向上迭代出最佳解，即每一步我都选择最好的解法，那么到最后我肯定是最佳解。
```
class Solution {
    
    public int minCostClimbingStairs(int[] cost) {
        if (cost == null || cost.length == 0)
            return 0;
        if (cost.length == 1)
            return cost[0];
        int[] dp = new int[cost.length + 1];

        //这是BASECASE
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i <= cost.length; i++) {
            dp[i] = Math.min(dp[i - 1], dp[i - 2]) + (i == cost.length ? 0 : cost[i]);
        }
        
        return dp[cost.length];
    }
}
```
通过状态转移方程我们不难发现，其实我们只需要前面的两个状态即可，所以我们不需要一个数组，只需要两个变量保存前面两个状态的值即可，以及一个临时变量协助进行状态转移。
```
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int dp_i_1 = 0, dp_i_2 = 0;
        for (int i = 0; i <= cost.length; i++) {
            int dp_i = Math.min(dp_i_1, dp_i_2) + (i == cost.length ? 0 : cost[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        
        return dp_i_1;
    }
}
```
其实动态规划并不难，首先我们能想到的就是递归解决，但会超时，那么我们会想到使用备忘录进行优化递归解法，然后可以想到，使用动态规划解决问题。只要把状态方程列出来，那么问题自然就解决了。