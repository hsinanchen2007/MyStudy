# 思路
**采用动态规划**
1. 问题拆解
    对于阶梯i，由于一次可以上一阶或两阶，因此必定需要从i - 1阶或i - 2阶上来(0, 1阶除外，这是边界)
2. 公式：
    对于该题，需要计算登上顶部花费的最小体力，因此有：

$$
\begin{cases}
dp[i] & = cost[i] , & \text{$(i = 0,1)$} \\
dp[i] & = min(dp[i - 1], dp[i - 2]) + cost[i], & \text{$(i \gt 1)$}
\end{cases}
$$

可能会有人迷惑 `可以选择从索引为 0 或 1 的元素作为初始阶梯` 这一点，其实可以当做从平地作为起点，登一步到阶梯0，两步到阶梯1

# 代码
## `CPP`
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len < 2) { 
            return 0;
        } else {
            int dp[len];
            dp[0] = cost[0];
            dp[1] = cost[1];
            for (auto i = 2; i < len; i++) {
                dp[i] = (dp[i - 1] < dp[i - 2] ? dp[i - 1] : dp[i - 2]) + cost[i];
            }
            return (dp[len - 1] < dp[len - 2] ? dp[len - 1] : dp[len - 2]);
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/7b067afa7f44e051edc2d13d82ef7f73d288e680af89de9d890f5d34a3c91980-image.png)


## `go`
```go
func minCostClimbingStairs(cost []int) int {
    _len := len(cost)
    if _len < 2 {
        return 0
    } else {
        dp := make([]int, _len)
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i := 2; i < _len; i++ {
            if dp[i - 1] < dp[i - 2] {
                dp[i] = dp[i - 1] + cost[i]
            } else {
                dp[i] = dp[i - 2] + cost[i]
            }
        }
        if dp[_len - 1] > dp[_len - 2] {
            return dp[_len - 2]
        } else {
            return dp[_len - 1]
        }
    }
}
```
![image.png](https://pic.leetcode-cn.com/1f900953b374aa5924f13e801e576934765e3d53fbb98e2bc70060b6d77fa643-image.png)


## `python`
```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        _len = len(cost)
        if _len < 2:
            return 0
        else:
            dp = [0]*_len
            dp[:2] = cost[:2]
            for i in range(2, _len):
                dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
            return min(dp[-1], dp[-2])
```
![image.png](https://pic.leetcode-cn.com/e05246d8c518e7a1a5727fb6050b265dc6bbc63fe91839dc5ba8fefebda5e5d4-image.png)



# 复杂度
- 时间复杂度：遍历了一遍，因此时间复杂度为$o(n)$
- 空间复杂度：使用了额外的`dp`，因此空间复杂度为$o(n)$