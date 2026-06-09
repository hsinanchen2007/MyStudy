首先来思考下朴素的动态规划解法：
设 $f(i)$ 是在前 i 个订单里最优选择方案的最大值，设 orders 为订单数组，下标从 1 开始，那么 $f(i)$ 有：
$$f(i) = \left\{ \begin{array}{c}
orders[1]& i = 1\\ 
max(orders[1], orders[2])& i = 2\\
max(f(i-1), f(i-2) + orders[i])& i > 2\\  
\end{array}\right. $$

$i = 1$ 和 $i = 2$ 时很好理解。
当 $i > 2$ 时，是一个类似斐波那契数列形式的递推式子，其意义是：
当我们已知 $f(i-1)$ 和 $f(i-2)$ 时，我们可以决定$f(i)$是否包含$orders[i]$。
#### 当我们不选择 orders[i]时：
$f(i) = max(f(j)), j∈[1,i-1]$。因为$f(y) <= f(x), y < x$, 所以 f(i) = f(i-1)。

#### 当我们选择 orders[i] 时：
因为$f(i-1)$可能包含$orders[i-1]$，所以选择 orders[i] 时，只能有 $f(i) = max(f(j)) + orders[i], j ∈ [1, i-2]$。
又因为$f(y) <= f(x), y < x$，所以$f(i) = f(i-2) + orders[i]$。

**综上所述，可以得出 $i>2$ 时的递推式**
接下来先看下**伪代码**：
```
const int MAXN = 1000;
int dp[MAXN] = {0};
dp[1] = orders[1];
dp[2] = max(orders[1], orders[2]);
for(int i = 3;i <= n; i++) {
    dp[i] = max(dp[i-1], dp[i-2] + orders[i]);
}
return dp[n];
```
我们发现在 for循环中，只用到了 dp[i], dp[i-1], dp[i-2] 三个位置。那么dp数组有点**浪费**呀。
我们可以使用**滚动数组的思想**来进行优化。
**滚动数组是递推问题常见的优化手段，即对一段内存重复使用，让有效的数据覆盖过期的数据**。
以 [2,7,9,3,1] 为例，如下图所示：
![滚动数组.png](https://pic.leetcode-cn.com/c0b6c5776b72fde417156e7c25bdbd3037e2174a77b6df4507e1ec9d68a13d9e-%E6%BB%9A%E5%8A%A8%E6%95%B0%E7%BB%84.png)
```
class Solution {
public:
    int massage(vector<int>& nums) {
        int ppre = 0, pre = 0, now = 0;
        for(int i = 1, n = nums.size(); i <= n; i++) {
            ppre = pre; pre = now;
            now = max(pre, ppre + nums[i-1]);
        }
        return now;
    }
};
```
