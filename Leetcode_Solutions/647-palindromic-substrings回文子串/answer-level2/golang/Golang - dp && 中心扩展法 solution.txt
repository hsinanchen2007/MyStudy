### 解题思路
中心扩展法更快，主要是因为能够更早地截断遍历（即：一旦有首尾字符不一致立刻return）。

### 代码

```golang
// dp
func countSubstrings(s string) int {
    length := len(s)
    res := 0
	dp := make([][]bool, length, length)
	for i := 0; i < length; i++ {
		dp[i] = make([]bool, length, length)
	}
    for j := 0; j < length; j++ {
        for i := j; i >= 0; i-- {
            if s[i] == s[j] && ((j - i < 2) || dp[i + 1][j - 1]) {
                    dp[i][j] = true
                    res++
                }
        }
    }
    return res
}


// 中心扩展法
func countSubstrings(s string) int {
    res := 0
    for i := 0; i < len(s); i++ {
        res += countPalindrome(s, i, i)
        res += countPalindrome(s, i, i+1)
    }
    return res
}

func countPalindrome(s string, start, end int) int {
    count := 0
    for start >= 0 && end < len(s) && s[start] == s[end] {
        count++
        start--
        end++
    }
    return count
}

```