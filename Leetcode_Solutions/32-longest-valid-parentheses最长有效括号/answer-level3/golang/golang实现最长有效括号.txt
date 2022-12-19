### 解题思路
这个问题的难点主要在于为什么只判断str[i - 1 - dp[i - 1]] == '('的情况，而不判断str[i - 1 - dp[i - 1]] == ')'的情况，
这是因为这种情况包含在dp[i - 1]中，也即在dp[i - 1]时就会把前面包含"(...)"的情况包含进来。

### 代码

```golang
func longestValidParentheses(str string) int {
	longest := 0
	if len(str) < 2 {
		return longest
	}

	dp := make([]int, len(str))
	dp[0] = 0
	if str[1] == '(' {
		dp[1] = 0
	} else if str[0] == '(' {
		dp[1] = 2
		longest = 2
	}
	for i := 2; i < len(str); i++ {
		if str[i] == '(' {
			dp[i] = 0
			continue
		}

		if str[i - 1] == '(' { // ...()
			dp[i] = dp[i - 2] + 2
		} else { // ...))
			if i - 1 - dp[i - 1] < 0 {
				dp[i] = 0
			} else if str[i - 1 - dp[i-1]] == '(' { // ...[(](...))
				if i - 1 - dp[i - 1] - 1 < 0 {
					dp[i] = dp[i - 1] + 2
				} else {
					dp[i] = dp[i-1] + 2 + dp[i - 1 - dp[i - 1] - 1]
				}
			}
		}
		if dp[i] > longest {
			longest = dp[i]
		}
	}

	return longest
}
```