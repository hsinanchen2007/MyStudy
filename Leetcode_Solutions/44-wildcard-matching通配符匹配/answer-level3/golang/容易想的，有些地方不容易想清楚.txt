1、指针移动

这种方法比较容易想到，但细节不容想清楚；特别是在当前str字符不匹配，并且当前pattern字符不是'?'、'*'时，要回溯时有点绕

```golang
func isMatch(s string, p string) bool {
	i := 0
	j := 0

	strStarIdx := 0 // string中匹配'*'的位置
	patStarIdx := -1    // pattern中出现'*'的位置
	for i < len(s) {
		if j < len(p) && (s[i] == p[j] || p[j] == '?') {
			i++
			j++
		} else if j < len(p) && p[j] == '*' {
			strStarIdx = i
			// 这里记录下pattern中'*'出现的位置，是为了可以找到pattern中'*'后面的那个字符
			// 因为在后面str匹配不上的时候，要认为str中的字符被pattern中的'*'匹配了，继续往后比较
			patStarIdx = j
			// 这里没有i++，因为*可以匹配0个字符
			j++
		} else if patStarIdx != -1 {
			// 如果str和pattern的当前字符没有匹配上，并且pattern中的前一个字符是'*'，
			// 那就让'*'尽可能多的匹配，都认为是和'*'匹配和(直到在str中找到匹配的字符)

			j = patStarIdx + 1 // j指向pattern中'*'后面的那个字符，每次不匹配后，都从'*'后的字符重新匹配
			strStarIdx += 1 // 如果str不匹配pattern中'*'后面的那个字符，则让str往后走，都认为是和'*'匹配
			i = strStarIdx
		} else {
			return false
		}
	}

	for ; j < len(p); j++ {
		if p[j] != '*' {
			return false
		}
	}

	return true
}
```

2、动态规划

这种方法比较难想，但里没有上面的绕，思路比较清晰；为了清楚的展示思路，我把一些可以合并的流程分解开了。
这里用到dp数组，空间上要比指针法差，但时间也比指针法长，就有点不能理解了；动态规划没有回溯的过程，按说应该更快的。

```golang
     0        p
  |-----|-----------|
 0|false|           |
  ------------------|
  |     |           |
  |     |           |
  |     |           |
  |     |           |
s |     |           |
  |     |           |
  |     |           |
  |     |           |
  |     |           |
  |-----|-----------|


func isMatch(s string, p string) bool {
	// 因为要处理两个string最开始为空的情况，所以都多申请了一个字节
	dp := make([][]int, len(s) + 1)
	for i := 0; i <= len(s); i++ {
		dp[i] = make([]int, len(p) + 1)
	}
	dp[0][0] = 1 // s:"", p:""，应该返回true

	flag := 1
	for j := 1; j <= len(p); j++ {
		if p[j - 1] != '*' {
			// 只要有不为'*'的字符，后续dp[0][j]都为false，
			// 例如：s:"", p:"*abc*"，结果为false，因为s中没有能匹配"abc"的
			flag = 0 
		}
		dp[0][j] = flag
	}

	for i := 1; i <= len(s); i++ {
		for j := 1; j <= len(p); j++ {
			// 这里要注意，i、j并不是s、p的下标，而是dp的下标，是s、p下标+1

			if s[i - 1] == p[j - 1] || p[j - 1] == '?' {
				// 当前字符匹配了，就看前面一个dp的值
				if dp[i - 1][j - 1] == 1 {
					dp[i][j] = 1
				}
			} else if p[j - 1] == '*' {
				if dp[i - 1][j] == 1 { // s:"abcde", p:"ab*"
					dp[i][j] = 1
				} else if dp[i][j - 1] == 1 { // s:"ab", p:"ab*"
					dp[i][j] = 1
				}
			}
		}
	}

	return dp[len(s)][len(p)] == 1
}
```
