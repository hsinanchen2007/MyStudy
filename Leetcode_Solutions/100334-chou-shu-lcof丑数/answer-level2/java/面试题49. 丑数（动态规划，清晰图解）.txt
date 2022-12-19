#### 解题思路：

> **丑数的递推性质：** 由于丑数只包含因子 $2, 3, 5$ ，因此较大的丑数一定能够通过 **某较小丑数 $\times$ 某因子** 得到。

- 设已知长度为 $n$ 的丑数序列 $x_1, x_2, ... , x_n$ ，求第 $n+1$ 个丑数 $x_{n+1}$  。根根据递推性质，下一个丑数 $x_{n+1}$ 只可能是以下三种情况其中之一（索引 $a, b, c$ 为未知数）：

$$
x_{n+1} =
\begin{cases}
x_{a} \times 2 & ,a \in [1, n] \\
x_{b} \times 3 & ,b \in [1, n] \\
x_{c} \times 5 & ,c \in [1, n]
\end{cases}
$$

- 由于 $x_{n+1}$ 是 **最接近** $x_n$ 的丑数，因此索引 $a, b, c$ 一定满足以下条件：

$$
\begin{cases}
x_{a} \times 2 > x_n \geq x_{a-1} \times 2 & ，即 x_a 为首个乘以 2 后大于 x_n 的丑数 \\
x_{b} \times 3 > x_n \geq x_{b-1} \times 3 & ，即 x_b 为首个乘以 3 后大于 x_n 的丑数 \\
x_{c} \times 5 > x_n \geq x_{c-1} \times 5 & ，即 x_c 为首个乘以 5 后大于 x_n 的丑数 \\
\end{cases}
$$

- 若索引 $a,b,c$ 满足以上条件，则可使用递推公式计算下个丑数 $x_{n+1}$ ，其为三种情况中的**最小值**，即：

$$
x_{n+1} = \min(x_{a} \times 2, x_{b} \times 3, x_{c} \times 5)
$$

![Picture1.png](https://pic.leetcode-cn.com/837411664f096417badf857fa51e77fd30cb1309a5637c37d24d8a4a48a42b03-Picture1.png){:width=500}

##### 动态规划解析：

- **状态定义：** 设动态规划列表 $dp$ ，$dp[i]$ 代表第 $i + 1$ 个丑数。
- **转移方程：**
  1. 当索引 $a, b, c$ 满足以下条件时， $dp[i]$ 为三种情况的最小值；
  2. 每轮计算 $dp[i]$ 后，需要更新索引 $a, b, c$ 的值，使其始终满足方程条件，以便下轮计算。实现方法：**分别独立判断** $dp[i]$ 和 $dp[a] \times 2$ , $dp[b] \times 3$ ,  $dp[c] \times 5$ 的大小关系，若相等则将对应索引 $a$ , $b$ , $c$ 加 $1$ 。

$$
\begin{cases}
dp[a] \times 2 > dp[i-1] \geq dp[a-1] \times 2 \\
dp[b] \times 3 > dp[i-1] \geq dp[b-1] \times 3 \\
dp[c] \times 5 > dp[i-1] \geq dp[c-1] \times 5 \\
\end{cases}
$$

$$
dp[i] = \min(dp[a] \times 2, dp[b] \times 3, dp[c] \times 5)
$$

- **初始状态：** $dp[0] = 1$ ，即第一个丑数为 $1$ ；
- **返回值：** $dp[n-1]$ ，即返回第 $n$ 个丑数。

<![Picture2.png](https://pic.leetcode-cn.com/1f01be7d87c8940d05825505a4774be98fb4ed31f22b89da3593fa7ebe9e67ea-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/40b011fa51667716f283d045ad07c838ef3c7f795a7fe4df1ae2ff44623bb5e0-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/4f4c9a6d3a0d16f8e11234b5034809917cd813ebfc084f63b07212f3a94a4204-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/f5e56edc2df473d52639729badf5da336befbb35ec848e0f0be475d7448912d9-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/eaa6b047273f6a66b605d4357a37350d3d551cf7df58cdfdda8d6398db6eea57-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/0b2976580d38fca8f9c2a4f9a2b13f34bde04a39726fbf747909c6d74ded1895-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/0b45eec656788933b2fdabd5350c1e8db6ea8ef6458f6f8d33c31a56904b6feb-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/d555c397f70566b4912eae5478639647b2cd08e78b8a3bdf18dfaa6f04b6af37-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/424b1e290f0a0effe4d5c0348d0098e7d3d66de05a765a008c3da52d568e4aad-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/d6e357a55c19aaca9b1a194721509e68fb1317a64a589040b1e470af5237cc7b-Picture11.png)>

**复杂度分析：**

- **时间复杂度 $O(N)$ ：** 其中 $N = n$ ，动态规划需遍历计算 $dp$ 列表。
- **空间复杂度 $O(N)$ ：** 长度为 $N$ 的 $dp$ 列表使用 $O(N)$ 的额外空间。

#### 代码：

```python []
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp, a, b, c = [1] * n, 0, 0, 0
        for i in range(1, n):
            n2, n3, n5 = dp[a] * 2, dp[b] * 3, dp[c] * 5
            dp[i] = min(n2, n3, n5)
            if dp[i] == n2: a += 1
            if dp[i] == n3: b += 1
            if dp[i] == n5: c += 1
        return dp[-1]
```

```java []
class Solution {
    public int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        int[] dp = new int[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = Math.min(Math.min(n2, n3), n5);
            if(dp[i] == n2) a++;
            if(dp[i] == n3) b++;
            if(dp[i] == n5) c++;
        }
        return dp[n - 1];
    }
}
```