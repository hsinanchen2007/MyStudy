使用strings.Builder进行字符串的拼接，执行用时从用"+"拼接的8ms，38.08%，提高到了0ms，100%
```golang
func reverseWords(s string) string {
	s = " " + s //开头可能没有空格，最后一个单词无法处理
	n := len(s)
	l := n - 1
	r := n

	var res strings.Builder
	for ; l >= 0; l-- {
		if s[l] == ' ' {
			sub := s[l+1 : r]
			if len(sub) != 0 {
				res.WriteString(sub)
				res.WriteString(" ")
			}
			r = l
		}
	}

	return strings.TrimSpace(res.String())
}
```
<br>
```golang
//或者这样写
func reverseWords(s string) string {
	s = " " + s
	n := len(s)
	l := n - 1
	r := n - 1

	var res strings.Builder
	for ; l >= 0; l-- {
		if s[l] == ' ' {
			sub := s[l+1 : r+1]
			if len(sub) != 0 {
				res.WriteString(sub)
				res.WriteString(" ")
			}
			r = l - 1
		}
	}
	return strings.TrimSpace(res.String())
}

```

![Snipaste_2020-01-22_19-51-46.png](https://pic.leetcode-cn.com/d076fb528b3850dd3ef66281b3eb203024fb2e61cf3b5c26effce68dbf409147-Snipaste_2020-01-22_19-51-46.png)

