// 思路挺简单的：就是上满一车就走，多退少补
// 1. 遍历所有单词分段，原则是一组单词长度和加上所需最少空格数不能超过 maxWidth
// 2. 对分好的每组，计算需要补多少空格，算法也简单
// 假设一组单词有 n 个，需要插入空格则是 w = maxWidth-sum(n), 其中sum(n)表示n个单词长度和
// 那么每个插入位置至少要分配得到 w/(n-1) 个空格，然后余下的 w%(n-1) 个空格可以随机分配
// 3. 需要特别处理的是最后一组，最后一组每个单词间隔一个空格，不足maxWidth的部分补上空格就行

```golang
func fullJustify(words []string, maxWidth int) []string {
	lines := make([]string, 0)
	width, left := 0, 0
	for i := 0; i < len(words); i++ {
		width += len(words[i])
		space := i - left
		// 如果加上该单词长度超出，则不能加上这个逼
		if width+space > maxWidth {
			lines = append(lines, jbspace(words[left:i], width-len(words[i]), maxWidth))
			width, left = len(words[i]), i
		}
	}
	if left < len(words) {
		last := strings.Join(words[left:], " ")
		lines = append(lines, last+nbspace(maxWidth-len(last)))
	}
	return lines
}

func jbspace(s []string, w, mw int) string {
	if len(s) == 1 {
		return s[0] + nbspace(mw-w)
	}
	n := (mw - w) / (len(s) - 1)
	m := (mw - w) % (len(s) - 1)
	ns, ts := nbspace(n), ""
	for i := 0; i < len(s)-1; i++ {
		ts += s[i] + ns
		if i < m {
			ts += " "
		}
	}
	return ts + s[len(s)-1]
}

func nbspace(n int) string {
	s := ""
	for i := 0; i < n; i++ {
		s += " "
	}
	return s
}
```