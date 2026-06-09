遇到 `(` 入栈， 遇到 `)` 将第一个或者最后一个 `(` 出栈， 如果栈为空，把对应的 `)` 去掉。
最后把多余的 `(` 去掉即可
```
func minRemoveToMakeValid(s string) string {
	b := []byte(s)
	pre := []int{}
	for i := 0; i < len(b); i++ {
		if b[i] == '(' {
			pre = append(pre, i)
		} else if b[i] == ')' {
			if len(pre) == 0 {
				b[i] = byte(' ')
			} else {
				pre = pre[1:]
			}
		}
	}
	for i := 0; i < len(pre); i++ {
		b[pre[i]] = byte(' ')
	}
	return strings.Replace(string(b), " ", "", -1)
}
```
