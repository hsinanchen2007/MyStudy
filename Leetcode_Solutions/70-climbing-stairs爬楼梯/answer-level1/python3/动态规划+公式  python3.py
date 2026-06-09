# 题解
典型的斐波那契数列问题，可使用递归算法，复杂度太高，这里不做介绍。
仅介绍动态规划和公式法
## 动态规划

 1. 初试化$dp=[0,...,0]$，长度为$n+1$。
 2. 若$n<2$，返回$1$
 3. 初始化$dp[1]=1,dp[2]=2$
 4. 遍历，遍历区间$[3,n+1)$：
 	+ $dp[i]=dp[i-1]+dp[i-2]$，即当前层的方法数等于前一阶的方法数加上前两阶的方法数。
 
 5. 返回$dp[n]$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def climbStairs(self, n: int) -> int:
        dp=[0]*(n+1)
        dp[1]=1
        if(n<2):
            return dp[n]
        dp[2]=2
        for i in range(3,n+1):
            dp[i]=dp[i-1]+dp[i-2]
        return dp[n]
```

## 公式
斐波那契公式的应用
第$n$个斐波那契数的公式： 
$$F_{n}=1 / \sqrt{5}\left[\left(\frac{1+\sqrt{5}}{2}\right)^{n}-\left(\frac{1-\sqrt{5}}{2}\right)^{n}\right]$$
### 复杂度分析
 - 时间复杂度：$O\left(log(n)\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        import math
        sqrt5=5**0.5
        fibin=math.pow((1+sqrt5)/2,n+1)-math.pow((1-sqrt5)/2,n+1)
        return int(fibin/sqrt5)
```
![在这里插入图片描述](https://pic.leetcode-cn.com/f7f5c2679b36f33a848aa7f34aee4718b069fc2e689e1968f48a17264a894283.png)