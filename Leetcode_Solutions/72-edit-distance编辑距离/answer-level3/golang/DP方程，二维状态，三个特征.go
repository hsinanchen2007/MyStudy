### 解题思路
此处撰写解题思路

### 代码

```golang
func minDistance(word1 string, word2 string) int {
    // DP方程 
    // word1[i-1],word2[j-1] 相同 dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1])
    // word1[i-1],word2[j-1]不同，dp[i][j] =1+ min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]
    l1 := len(word1)
    l2 := len(word2)
    // 一个是空则编辑距离是另一个字符串长
    if l1 == 0 {
        return l2
    }
    if l2 == 0 {
        return l1
    }
    var dp [][]int

    // 初始化
    for i := 0; i <= l1; i++ {
        var tmp []int
        for j := 0; j <= l2; j++ {
            if i == 0 {
                tmp = append(tmp, j)
            } else if j == 0 {
                tmp = append(tmp, i)
            } else {
                tmp = append(tmp, 0)
            }
        }
        dp = append(dp, tmp)
    }
    for i := 1;i <= l1; i++ {
        for j := 1; j <= l2; j++ {
            if word1[i-1] == word2[j-1] {
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1])
            } else {
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1)
            }
        }
    }
    return dp[l1][l2]
}

func min(a, b, c int) int {
    tmp := a
    if b < tmp {
        tmp = b
    }
    if c < tmp {
        tmp = c
    }
    return tmp
}

```