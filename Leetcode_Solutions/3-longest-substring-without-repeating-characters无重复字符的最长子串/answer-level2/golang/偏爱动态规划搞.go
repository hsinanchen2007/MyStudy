对于字符串S[0:j]，已确定的以S[j]结尾的最长无重复子串为 S[i:j], 则对于以S[j+1]结尾的最长无重复子串求解分两种情况

- 如果 S[j+1] 不存在于 S[i:j] 子串中，则解为 S[i:j+1]
- 如果 S[j+1] 存在于 S[i:j] 子串中，则解为 S[k:j+1], k 为字符 S[j+1] 在 S[0:j+1] 中最后出现的位置索引

注：对于 K 的寻找，可以使用map来快速定位

示例代码
```
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	// cache 记录某个字符最近一次出现的位置
	cache := map[byte]int{
		s[0]: 0,
	}
	// dp 每一项都是一个两位数组，记录以 s[i] 字母结尾的最长无重复子串的首位索引
	dp := make([][]int, len(s))
	dp[0] = []int{0, 0}
	for i := 1; i < len(s); i++ {
		idx, ok := cache[s[i]]
		if !ok || idx < dp[i-1][0] {
			dp[i] = []int{dp[i-1][0], i}
		} else {
			dp[i] = []int{idx + 1, i}
		}
		cache[s[i]] = i
	}
	l := 0
	for _, d := range dp {
		dl := d[1] - d[0] + 1
		if l < dl {
			l = dl
		}
	}
	return l
}

```
