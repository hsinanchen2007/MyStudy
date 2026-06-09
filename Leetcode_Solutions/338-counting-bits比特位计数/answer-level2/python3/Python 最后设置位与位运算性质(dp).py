
# Python 最后设置位与位运算性质(dp)

## 方法一：最后设置位

最后设置位是从右到左第一个为**1**的位。使用**x&=x-1**将该位设置为0，得到状态转移方程：

$dp(i)=dp(i \&(i-1))+1$


```python
class Solution:
    def countBits(self, num: int) -> List[int]:

        dp=[0]*(num+1)

        for i in range(1,num+1):

            dp[i]=dp[i & (i-1)]+1

        return dp
```

## 方法二：位运算性质(dp)

二进制的两个特性：

1. 奇数的二进制中**1**的个数=它上一位偶数的二进制中1的个数+1
2. 偶数的二进制中**1**的个数=这个偶数**除以2**后的数二进制1的个数

状态转移方程公式为：

$d p[i]=\left\{\begin{array}{ll}d p[i-1]+1 & i为奇数 \\ d p[i / / 2] & i为偶数 \end{array}\right.$


```python
class Solution:
    def countBits(self, num: int) -> List[int]:

        dp=[0]*(num+1)

        for i in range(1,num+1):

            if i%2==1:
                dp[i]=dp[i-1]+1
            else:
                dp[i]=dp[i//2]

        return dp
```
