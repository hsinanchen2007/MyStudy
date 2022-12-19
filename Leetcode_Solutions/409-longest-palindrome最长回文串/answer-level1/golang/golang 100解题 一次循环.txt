### 解题思路
用数组存统计字符次数，双数次的字符代表可以组成回文，奇数的字符取一个可以当中心点

### 代码

```golang
func longestPalindrome(s string) int {
	apl, res := [52]uint8{}, 0
	for i := range s {
		k := s[i] - 'a' + 'Z' - 'A'
		if s[i] <= 'Z' {
			k = s[i] - 'A'
		}
		// 偶数可以用作回文，所以直接+2
		if apl[k]++; apl[k]&1 == 0 {
			res += 2
		}
	}
	if len(s)-res > 0 {
		res++
	}
	return res
}

```