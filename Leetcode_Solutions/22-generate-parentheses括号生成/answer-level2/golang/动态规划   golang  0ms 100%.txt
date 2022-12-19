### 解题思路
动态规划，将问题分解为前缀字符串（str） + 后续字符串（fn(n-1)）
每一步子问题中，前缀部分的处理考虑好不同 diff 的情况下可能出现的前缀可能即可
diff 为当前前缀中未补全的括号个数，从「不补容易一对括号」到「全补所有括号」处理完所有前缀后
往后递进处理 fn(n-1) 即可，直到处理完所有子问题

### 代码

```golang
var l int

func generateParenthesis(n int) (s []string) {
	l = n
	for _, v := range gen(n-1, 1, "(") {
		s = append(s, "("+v)
	}
	return s
}
func gen(n, diff int, prefix string) (ss []string) {
	for i := diff; i >= 0; i-- {
		var fill string
		for x := 0; x < i; x++ {
			fill += ")"
		}
		if n >= 1 {
			tmp := prefix + fill + "("
			for _, v := range gen(n-1, diff-i+1, tmp) {
				ss = append(ss, fill+"("+v)
			}
		} else {
			return []string{fill}
		}
	}
	return
}
```