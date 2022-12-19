![webwxgetmsgimg.jpeg](https://pic.leetcode-cn.com/c7a431e35007ed954e5c391c97488b7d38825e1ba6f566ecd7f8352d3e25f703-webwxgetmsgimg.jpeg)
看了大佬的思路写出来的，回过头来看觉得是对已有结论的推导，重点还是每一次得出这个点上两个串可不可以匹配的结论要准确可证明，对我来说不看答案想出这个解法还是太难了，希望下次能更有思路一些把
```
func isMatch(s string, p string) bool {
    dp := make([][]bool, 0, len(s)+1)
    for i:=0; i<len(s)+1; i++ {
        tmp := make([]bool, len(p)+1)
        dp = append(dp, tmp)
    }
    dp[0][0] = true
    for i, _ := range(s) {
        dp[i+1][0] = false
    }
    for i, ch := range(p) {
        if dp[0][i] && ch == '*' {
            dp[0][i+1] = true
        } else {
            dp[0][i+1] = false
        }
    }
    for i, chS := range(s) {
        for j, chP := range(p) {
            x, y := i+1, j+1
            if chP != '*' {
                if dp[x-1][y-1] && (chP == '?' || chP == chS) {
                    dp[x][y] = true
                } else {
                    dp[x][y] = false
                }
            } else {
                if dp[x][y-1] || dp[x-1][y] {
                    dp[x][y] = true
                } else {
                    dp[x][y] = false
                }
            }
        }
    }
    return dp[len(s)][len(p)]
}
```
