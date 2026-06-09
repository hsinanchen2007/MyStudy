### 解题思路
#### 没想到这题居然可以使用贪心策略求解
+ 当长度为 1-4 可以作为基本情况，枚举返回。
+ 当长度 >4,例如，4,5,6,7,8,9 ...,  就每次剪去长度为 3 的一段下来，最后剩下的一段必然为2,3,4, 不用再分了


DP 算法也可以求解，但我之前不知道为何在剑指offer对应习题上一直提交不对， DP没有写对很尴尬。
看到了liweiwei 大神的解法，每次只需要枚举 dp[i] = max(dp[i-1]*1, dp[i-2]*2, dp[i-3]*3) 即可。
虽然最初看起来也是 O(n^2)， 但状态空间变小了，dp[n][m] 变为了 dp[n]

### DP 解法最大的问题是，本题要求至少要切两段，
+ 当 n=2, 我们期望返回1， 当 n=3 我们期望返回2
+ 但是当 DP 调用时，我们期望 dp[2] = 2, dp[3] = 3。 比如说求 dp[5]=dp[2]*3, dp[3]*2, 这里 dp[2] 可以作为一段，而不需要再去切分，导致变为 1*1
+ 这里实际上只需要每次枚举切长度为2，还是切长度为3
+ liweiwei 代码为了解决上述问题，令 dp[2]=1, dp[3]=2, 然后每次取一个 max, 即 max(dp[i-2], i-2), max(dp[i-3], i-3)
+ [参考代码 5：使用“滚动数组”技巧](https://leetcode-cn.com/problems/integer-break/solution/tan-xin-xuan-ze-xing-zhi-de-jian-dan-zheng-ming-py/)， 用这个来解递归式非常好，例如 斐波那契数列。


### 贪心代码

```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        ## 贪心策略
        # 当大于 3 时，每次切 3 下来
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n == 4:
            return 4
        result = 1
        while n>4:
            result = 3*result
            n = n-3 
        result *= n
        return result
```

### DP 代码
```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        if n==3:
            return 2 # 对于后面的情况就不对，因为后面比如说 6 = 3+3， 这里 DP[3] 就该返回3
        ## DP
        dp = [0 for x in range(n+1)]
        dp[1] = 1
        dp[2] = 2
        dp[3] = 3
        for i in range(4, n+1):  
            dp[i] = max([dp[i-2]*2, dp[i-3]*3])  ## 这里 i-3 小心越界
        return dp[n]
```
#### 滚动数组版本
```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        if n==3:
            return 2 # 对于后面的情况就不对，因为后面比如说 6 = 3+3， 这里 DP[3] 就该返回3
        ## DP 滚动数组
        dp = [0, 1, 2, 3]
        for i in range(4, n+1):  
            dp[i%4] = max([dp[(i-2)%4]*2, dp[(i-3)%4]*3])  ## 这里 i-3 小心越界
        return dp[n%4]
```