### 代码

```golang
//dp[i][j]: word1[0...i]转换成word2[0...j]的最少操作数
//dp[i - 1][j] : 删除第i个
//dp[i - 1][j - 1] : 替换第i个
//dp[i][j - 1] : 添加一个字符和word2[j]一样的
func minDistance(word1 string, word2 string) int {
    rows := len(word1) + 1
    cols := len(word2) + 1
    dp := make([]int, cols)


    for j := 0; j < cols; j++ {//word2有几个字符, word1就要添加几个字符
        dp[j] = j
    }
    var leftUp int
    for i := 1; i < rows; i++ {
        leftUp = dp[0]
        dp[0] = i
        for j := 1; j < cols; j++ {
            temp := dp[j]
            if word1[i - 1] == word2[j - 1] {
                dp[j] = leftUp
            } else {
                dp[j] = min(min(dp[j - 1], dp[j]), leftUp) + 1
            }
            leftUp = temp
        }
    }
    return dp[cols - 1]
}

func min(x, y int) int {
    if x < y {
        return x
    } 
    return y
}
```