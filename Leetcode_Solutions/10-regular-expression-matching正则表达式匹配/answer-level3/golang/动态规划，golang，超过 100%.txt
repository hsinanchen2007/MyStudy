### 解题思路

```
越界情况，当做匹配失败。

初始化，
当 i = 0 时，
    当 j = 0 时，
		dp(0, 0) = p[0] == s[0] || p[0] == .
	当 j >= 1 时，
		dp(0, j) =
			当 p[j] = . 时，值为 p[0...j] 是否可以匹配空值。如 s=a，p=b*c*a，b*c* 可以匹配空值
			当 p[j] = * 时,
				当 p[j-1] == s[i] 或者 p[j-1] == . 时，值为 p[0...j] 是否可以匹配空值或者 dp(0, j-2)
					第一种情况，表明 p[j...j+1] 成功匹配，如 s=a, p=c*b*a*，第二种情况表明 p[j...j+1] 匹配失败或放弃匹配，如 s=a, p=a*b*c*，s=a, p=a*b*c*a*
				否则，值为 dp(0, j-2)。这种情况表明 p[j...j+1] 不能匹配到 s[0]，需要回退重试匹配。
			当 p[j] = 其他值时，值为 s[0] == p[j] && dp(i-1, j-1)
动态规划，
当 i >= 1 时，
	dp(0, j) =
		当 p[j] = . 时，值为 dp(i-1, j-1)。这个情况的含义是，在当前字符串模糊匹配情况成功下，只需要去掉 s[i] 和 p[j]，观察之前匹配情况
		当 p[j] = * 时,
			当 p[j-1] == s[i] 或者 p[j-1] == . 时，值为（虽然相等，但 p[j...j+1] 不进行匹配，s[i] 给后面进行匹配）dp（i,j-2) ||（匹配多次）dp[i-1][j]
			否则，值为 dp(0, j-2)。这种情况表明 p[j...j+1] 不能匹配到 s[i]，需要回退重试匹配
		当 p[j] = 其他值时，值为 s[i] == p[j] && dp(i-1, j-1)。这个情况的含义是，如果当前字符串模糊匹配情况成功，只需要观察之前匹配情况即可

```

### 代码

```golang
func isMatch(s string, p string) bool {
	slen, plen := len(s), len(p)
	if slen == 0 {
		if plen%2 != 0 {
			return false
		}
		for j := 1; j < plen; j += 2 {
			if p[j] != '*' {
				return false
			}
		}
		return true
	}
	if plen == 0 {
		return slen == 0
	}
	dp := make([][]bool, slen, slen)
	for i := 0; i < slen; i++ {
		dp[i] = make([]bool, plen, plen)
	}
	// init: dp(0, j)
	dp[0][0] = p[0] == s[0] || p[0] == '.'
	for canPreEmpty, j := true, 1; j < plen; j += 1 {
		if canPreEmpty && j%2 == 1 && p[j] != '*' {
			canPreEmpty = false
		}
		switch p[j] {
		case '.':
			dp[0][j] = canPreEmpty
		case '*':
			if p[j-1] == s[0] || p[j-1] == '.' {
				dp[0][j] = canPreEmpty || (j >= 2 && dp[0][j-2])
			} else {
				dp[0][j] = j-2 >= 0 && dp[0][j-2]
			}
		default:
			dp[0][j] = s[0] == p[j] && canPreEmpty
		}
	}
	// cal: dp(i, j)
	for i := 1; i < slen; i++ {
		for j := 1; j < plen; j++ {
			switch p[j] {
			case '.':
				dp[i][j] = dp[i-1][j-1]
			case '*':
				if p[j-1] == s[i] || p[j-1] == '.' {
					dp[i][j] = (j-2 >= 0 && dp[i][j-2]) || dp[i-1][j]
				} else {
					dp[i][j] = j-2 >= 0 && dp[i][j-2]
				}
			default:
				dp[i][j] = s[i] == p[j] && dp[i-1][j-1]
			}
		}
	}
	return dp[slen-1][plen-1]
}
```