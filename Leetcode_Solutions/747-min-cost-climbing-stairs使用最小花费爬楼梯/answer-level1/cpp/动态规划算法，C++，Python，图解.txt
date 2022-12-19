按结果分析，最终结果可以从倒数第一个到达和倒数第二个到达

1. 假设只有两个元素

此时的结果就是 `cost[0]` 和 `cost[1]` 中最小的那个

2. 假设只有三个元素分别为 1，2，3

   我们可以一眼看出最小的结果即为 2。仔细观察就会发现，我们取了爬到 2 和 3 元素的最小值，因为爬到 2 元素消耗为2，爬到 3 元素消耗为 3。

   1. 为何爬到 3 元素消耗为 3 呢

   因为我们选择了 1 元素为起始点，并且略过了 2 元素

   2. 爬到 3 元素的表达式怎么写?

   `min(cost[0], cost[1]) + cost[3]`

   3. 比较爬到 3 元素和 2 元素的消耗，不难得出最终登上楼梯的最小消耗为 2
   4. 根据动态规划思想写转移方程

   `dp[0] = cost[0]` 、`dp[1] = cost[1]`、`dp[2] = min(dp[0] + dp[1]) + cost[2]`

3. 将 `3`  个元素的转移方程推广到 `n` 个元素

`dp[n] = min(dp[n-1] + dp[n-2]) + cost[n]` 此时 n > 2

### 图解如下：
采用了官方的例子：
![未命名.gif](https://pic.leetcode-cn.com/a433f9e7b36052bd5f3491f86ad50ec0e554d4b0adfa4ede4b61fb2fb137588b-%E6%9C%AA%E5%91%BD%E5%90%8D.gif)


```python []
class Solution:
    def minCostClimbingStairs(self, cost: [int]) -> int:
        length = len(cost)
        dp = [cost[0], cost[1]]
        for index in range(2, length):
            print(dp)
            dp.append(min(dp[index - 2], dp[index - 1]) + cost[index])
        return min(dp[-1], dp[-2])
```
```c++ []
class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp{cost[0], cost[1]};
        for (int i = 2; i < cost.size(); i++) {
            dp.push_back(min(dp[i - 2], dp[i - 1]) + cost[i]);
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};
```
### 复杂度分析
1. 时间复杂度：O(n)
2. 空间复杂度：O(n)
   因为借用了 dp 数组，所以空间复杂度为 O(n)，此题也可以将 dp 数组修改为 两个变量从而实现空间复杂度为 O(1)的情况。