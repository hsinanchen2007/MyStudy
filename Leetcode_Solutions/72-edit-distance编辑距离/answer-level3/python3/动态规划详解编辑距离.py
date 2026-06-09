```
class Solution:
    def minDistance(self, word1, word2):
        #dp[i][j]表示将字符串 word1[0: i-1] 转变为 word2[0: j-1] 的最小步骤数
        length1=len(word1)
        length2=len(word2)
        dp=[[0 for j in range(length2+1)]for i in range(length1+1)]
        
        #边界情况
            #当 i = 0,即 word1 串为空时，那么转变为 word2 串就是不断添加字符，dp[0][j] = j。
            #当 j = 0,即 word2 串为空时，那么转变为 word2 串就是不断删除字符，dp[i][0] = i。
        if not word1 and not word2:
            return 0
        for j in range(length2+1):
            dp[0][j]=j
        for i in range(length1+1):
            dp[i][0]=i


        #三种操作
            #插入操作：dp[i][j - 1] + 1 相当于为 word2 串的最后插入了 word1 串的最后一个字符；
            #删除操作：dp[i - 1][j] + 1 相当于将 word2 串的最后字符删除 ;
            #替换操作：dp[i - 1][j - 1] +（word1[i - 1] != word2[j - 1]）相当于通过将 word2 串的最后一个字符替换为 word1aaaa 串的最后一个字符。

        for i in range(1,length1+1):
            for j in range(1,length2+1):
                if word1[i-1]==word2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1
        return dp[length1][length2]

if __name__ == "__main__":
    print(Solution().minDistance("horse","ros"))
    
```