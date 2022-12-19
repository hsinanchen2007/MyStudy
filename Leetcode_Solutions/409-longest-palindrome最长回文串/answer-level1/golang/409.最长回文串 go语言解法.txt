### 解题思路

 用两个数组分别存储每个大小写字母出现的个数，遍历两个数组，若当前元素%2等于0或者当前元素-1再%2等于0，则说明可以从中拿出当前元素个或者当前元素-1个字符来构成回文串，最后返回所有可以用来构成回文串的字符数之和即可。

### 代码

```golang
func longestPalindrome(s string) int {
	var up [26]int
	var lo [26]int
	var res int = 0
	for i := 0;i < len(s);i++ {
		if s[i] >= 'A' && s[i] <= 'Z' {
			up[s[i] - 'A'] += 1
		}
		if s[i] >= 'a' && s[i] <= 'z' {
			lo[s[i] - 'a'] += 1
		}
	}
	for j := 0;j < 26;j++ {
		if up[j] % 2 == 0 {
			res += up[j]
		}else if (up[j]-1) % 2 == 0 {
			res += up[j] - 1
		}
		if lo[j] % 2 == 0 {
			res += lo[j]
		}else if (lo[j]-1) % 2 == 0 {
			res += lo[j] - 1
		}
	}
	if res < len(s) {
		return res + 1
	}else {
		return res
	}
}
```