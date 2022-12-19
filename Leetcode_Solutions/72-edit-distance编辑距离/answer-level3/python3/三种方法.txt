1、递归
```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        """递归思想,速度太慢"""

        def dp(i,j):
            #word1到头，剩下的wrod2全部插入
            if i == -1:
                return j + 1
            #word2到头，剩下的wrod1全部删除
            if j == -1:
                return i + 1

            #如果对应的字符相等，不做操作,跳入下一个字符
            if word1[i] == word2[j]:
                return dp(i-1, j-1)
            else:
                #删除、插入、替换的最小情况
                del_ = dp(i-1, j) + 1
                insert = dp(i, j-1) +1
                replace = dp(i-1, j-1) + 1
                return min(del_, insert, replace)

        return dp(len(word1)-1, len(word2)-1)
```

2、对于重叠子问题可进行优化
```
def minDistance(word1: str, word2: str) -> int:
    """备忘录+递归思想"""
    
    #加个备忘录，有重叠子问题问题
    memo = {}
    
    def dp(i,j):
        #先从备忘录检索
        if (i,j) in memo:
            #print(1)
            return memo[(i,j)]
        #word1到头，剩下的wrod2全部插入
        if i == -1:
            return j + 1
        #word2到头，剩下的wrod1全部删除
        if j == -1:
            return i + 1
        
        #如果对应的字符相等，不做操作,跳入下一个字符
        if word1[i] == word2[j]:
            memo[(i,j)] = dp(i-1, j-1)
            return memo[(i,j)]
        else:
            #删除、插入、替换的最小情况
            del_ = dp(i-1, j) + 1
            insert = dp(i, j-1) +1
            replace = dp(i-1, j-1) + 1
            memo[(i,j)] = min(del_, insert, replace)
            return memo[(i,j)]
    
    return dp(len(word1)-1, len(word2)-1)

```

3、动态规划， DP table
```
def minDistance(word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        # 第一行
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j-1] + 1
        # 第一列
        for i in range(1, m + 1):
            dp[i][0] = dp[i-1][0] + 1
            
        for i in range(1, m+1):
            for j in range(1, n+1):
                #print(i,j)
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    
        return dp[-1][-1]
```
