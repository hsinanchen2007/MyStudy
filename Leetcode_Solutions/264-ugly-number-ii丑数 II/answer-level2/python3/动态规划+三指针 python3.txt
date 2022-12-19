### 解题思路
此处的动态规划转移方程不能定量的写出来，但是应该能感觉到第i个丑数是由前面的数X2/3/5造出来的
至于究竟X多少，需要找到这些数里面比前一个丑数大的最小的值
由此引入三指针的解法，真的太妙了，我等凡人万万想不出来hhhh
![捕获.PNG](https://pic.leetcode-cn.com/880693c247b36ed9045d2c20803fe83ab80e1b944ac6634ccd44dd426bbc564f-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1 for _ in range(n)]
        # 三指针初始化
        i2 = 0
        i3 = 0
        i5 = 0
        for i in range(1,n):
            min_val = min(dp[i2]*2,dp[i3]*3,dp[i5]*5)
            dp[i] = min_val
            # 找出哪个指针对应的数造出了现在这个最小值，将指针前移一位
            if dp[i2]*2 == min_val:
                i2 += 1
            if dp[i3]*3 == min_val:
                i3 += 1
            if dp[i5]*5 == min_val:
                i5 += 1
        return dp[-1]



```