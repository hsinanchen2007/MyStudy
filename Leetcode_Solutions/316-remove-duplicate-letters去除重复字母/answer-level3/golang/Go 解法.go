我们一步步来分析这个问题，首先我们比较容易得到的结论是：不考虑相对顺序不变和字典序最小的情况下，无论采用什么方法，得到的结果包含字符是一样的，即**出现的字符必然要在答案中出现(1)**。
然后我们再分析剩下两个条件：

1. 不改变字符出现的相对顺序，这个可以使用栈完成：**从左往右扫描，通过一系列的进栈出栈后，最后栈中剩余字符的相对顺序保持不变**；
2. 得到的字符串字典序最小，贪心策略：在扫描过程中，如果我们发现当前字符没有在栈中出现过且比栈顶元素要小，以及当前栈顶元素在剩余的字符串中还会出现(保证 1)，则将栈顶元素弹出，然后将当前元素进栈；

代码写得比较挫，仅供参考：

``` golang
func removeDuplicateLetters(s string) string {
    b := []byte(s)
	var r []byte
	for i, c := range b {
		if len(r) == 0 {
			r = append(r, c)
			continue
		}
		if bytes.IndexByte(r, c) != -1 {
			continue
		}
		for len(r) > 0 && c < r[len(r)-1] && bytes.IndexByte(b[i+1:], r[len(r)-1]) != -1 {
			r = r[:len(r)-1]
		}
		r = append(r, c)
	}

	return string(r)
}
```
