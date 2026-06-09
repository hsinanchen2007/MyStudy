
# 动态规划
1. dp初始化问题：dp实际是存储最大公共子串的默认值的数组，初始化为0，因为假设都是不存在重复子串嘛！
2. 越界问题：但是要设置多少个0呢？我们考虑到i+1，所以必须设置为len(A)+1,这里有两个数组,故dp=[[0]*(len(B)+1) for _ in range(len(A)+1)],其实这可看作是矩阵的常用写法。
3. 状态：dp为A和B的最长公共前缀，转移方程：dp[i+1][j+1]=dp[i][j]+1。在此之后（断开后）有可能会有更长的重复子串，故以result更新dp最大值，若是断开之后将会重新从0开始算，这就是初始化为啥要设为0了！！
5. 模板：动态方程一般都采用dp[i+1][j+1]=dp[i][j]+1，dp[i+1][j+1]=max(dp[i][j-1],dp[i-1][j])等类似的形式，然后一般会用res=max(dp[i+1][j+1],res)，存储最终结果。类似的题目还有许多，首页按标签搜就可以查到了！

```
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        dp=[[0]*(len(B)+1) for _ in range(len(A)+1)]
        res=0
        for i in range(len(A)):
            for j in range(len(B)):
                if A[i]==B[j]:
                    dp[i+1][j+1]=dp[i][j]+1
                    res=max(dp[i+1][j+1],res)
       return res
```

