### 解题思路
go实现
![image.png](https://pic.leetcode-cn.com/f3bf4db0400459b12e4b60e75f9c28074418517b543441db52ce010c6a84cfac-image.png)

### 代码

```golang
func min(a,b,c int) int {
    minNum := a
    if minNum > b {
        minNum = b
    }
    if minNum > c {
        minNum = c
    }
    return minNum
}

func minDistance(word1 string, word2 string) int {
    len1 := len(word1)
    len2 := len(word2)
    if len1 == 0 {
        return len2
    }
    if len2 == 0 {
        return len1
    }
    dp := make([][]int, len1 + 1)
    for i := 0; i <= len1; i++ {
        dp[i] = make([]int, len2 + 1)
        dp[i][0] = i
    }
    for j := 0; j <= len2; j++ {
        dp[0][j] = j
    }
    dp[0][0] = 0
    dp[1][0] = 1
    dp[0][1] = 1
    for i := 1 ; i <= len1; i++ {
        for  j := 1; j <= len2; j++ {
            if word1[i-1] == word2[j-1] {
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1])
            } else {
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)
            }
        }
    }
    return dp[len1][len2]
}
```