```
/*
72. 编辑距离
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
解题思路：构建动态规划表
1、dp[0][0] = 0
2、dp[i][0] = i
3、dp[0][j] = j
4、dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1  // word1[i-1]=word2[j-1], dp[i][j] = dp[i-1][j-1]
*/
func minDistance(word1 string, word2 string) int {
    lens1 := len(word1)
    lens2 := len(word2)
    dp := make([][]int, lens1+1)
    for i:=0; i< lens1+1; i++ {
        dp[i] = make([]int, lens2+1)
    }
    dp[0][0] = 0
    for i:=0; i< lens1+1; i++ {
        dp[i][0] = i
    }
    for j:=0; j< lens2+1; j++ {
        dp[0][j] = j
    }
    for i:=1; i < lens1+1; i++ {
        for j:=1; j< lens2+1; j++ {
            if word1[i-1] == word2[j-1] {
                dp[i][j] = dp[i-1][j-1]
            } else {
                dp[i][j] = getMin(dp[i-1][j], dp[i][j-1],  dp[i-1][j-1]) + 1
            }
        }
    }
    return dp[lens1][lens2]
}

func getMin(a, b, c int) int{
    if a<=b {
        if c<=a {
            return c
        }else {
            return a 
        }
    }
    if b<=a {
        if c <=b {
            return c
        }else {
            return b
        }
    }
    return  a
}
```
