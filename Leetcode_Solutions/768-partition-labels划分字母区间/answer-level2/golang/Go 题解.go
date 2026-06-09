遍历字符串，将当前出现过的字符经map去重后组成字符串，当该字符串中任意字符在当前位置之后的字符串中均不存在时，即为分割点，将当前分割长度计入数组，继续循环直至字符串末尾。

```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.4 MB, 在所有 Go 提交中击败了33.33%的用户
```
```Go []
func partitionLabels(S string) []int {
	ps := make([]int, 0)
	s := make(map[byte]int)
	begin := 0
	substr := ""
	for i := range S {
		if _, ok := s[S[i]]; !ok {
			substr += string(S[i])
			s[S[i]] = 0
		}
		if !strings.ContainsAny(S[i+1:], substr) {
			ps = append(ps, i-begin+1)
			begin = i + 1
			substr = ""
			s = make(map[byte]int)
		}
	}
	return ps
}
```

更多LeetCode题库Go语言题解参考[LeetCodeByGo](https://github.com/mrandmrsbenben/LeetCodeByGo)
