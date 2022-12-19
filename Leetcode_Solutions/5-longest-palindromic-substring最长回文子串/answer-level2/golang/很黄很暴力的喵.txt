### 解题思路
此题用暴力解，比较容易理解，针对奇数回文和偶数回文均做个判断。然后针对暴力的几种特殊情况，例如严重影响耗时的case，做单独的优化、特判处理即可。显然，我下面的代码还是可以优化的，不过意义不大。

### 代码

```golang
func longestPalindrome(s string) string {
    // 最大回文长度
	var maxPalindromeLength int = 1
	// 最大滑动窗口的起始点和结束点(循环变量i代替)
	var maxStartPos int = 0
	var maxEndPos int = 0
	if len(s) < 2 {
		return s
	}
	if strings.Count(s, string(s[0])) == len(s) {
		return s
	}
	// 很暴力, O(n^3), 有两种回文，奇数回文和偶数回文
	for i := 1; i < len(s); i++ {
		// 处理奇数回文
		for j, k := i - 1, i + 1; j >= 0 && k < 2 * i + 1 && k < len(s); j, k = j - 1, k + 1 {
			if s[j] == s[k] {
				if k - j + 1 - 2 >= maxPalindromeLength || k - j + 1 >= maxPalindromeLength && maxPalindromeLength == 1 {
					maxPalindromeLength = k - j + 1
					maxStartPos = j
					maxEndPos = k
				}
			} else {
				break
			}
		}
	}
	// 处理偶数回文
	for i := 0; i < len(s); i++ {
		for j, k := i, i + 1; j >= 0 && k <=
			2 * i + 1 && k < len(s); j, k = j - 1, k + 1 {
			if s[j] == s[k] {
				if k - j + 1 > maxPalindromeLength || k - j + 1 >= maxPalindromeLength && maxPalindromeLength == 1 {
					maxPalindromeLength = k - j + 1
					maxStartPos = j
					maxEndPos = k
				}
			} else {
				break
			}
		}
	}
	return s[maxStartPos:maxEndPos+1]
}
```