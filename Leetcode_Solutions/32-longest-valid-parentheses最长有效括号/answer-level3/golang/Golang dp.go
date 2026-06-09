### 解题思路
此处撰写解题思路

### 代码

```golang
func longestValidParentheses(s string) int {
    if len(s) == 0 {
        return 0
    }
    var (
        dp = make([]int,len(s))
        max = 0
    )
    dp[0] = 0
    for i := 1; i < len(s); i ++ {
        if s[i] == ')' {
            var pos int
            pos = i - dp[i-1] -1
            if pos >= 0 && s[pos] == '(' {
                if pos-1 >= 0 {
                    dp[i] = dp[i-1]+dp[pos-1]+2
                }else {
                    dp[i] = dp[i-1]+2
                }
            }
            if dp[i] > max {
                max = dp[i]
            }
        }
    }
    return max
}
```