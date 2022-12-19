![image.png](https://pic.leetcode-cn.com/e1d065bfc751a61c04f206f8c42aa213cd7e7df53e4a36e468d84a7b55cf4354-image.png)

```
func longestCommonPrefix(ss []string) string {
	// 如果参数长度为0或者第一个元素为"",直接返回""
	if len(ss) == 0 || ss[0] == "" {
		return ""
	}
	// 如果参数长度为1,直接返回参数
	if len(ss) == 1 {
		return ss[0]
	}
	// 如果参数中存在值为""的元素,直接返回""
	// 在这个地方先遍历,好处是如果参数切片很长且倒数第几个元素为"",那么节省时间不用进行后面的字符串比较了
	// 坏处是如果参数切片很长且不存在元素为"",那么就很浪费时间
	for _, v := range ss[1:] {
		if v == "" {
			return ""
		}
	}
	for _, v := range ss[1:] {
		// 取相比较的两个元素的长度比较,以小的值作为for循环的临界点,不然下面元素字符比较的时候会越界
		length := len(ss[0])
		if length > len(v) {
			length = len(v)
		}
		i := 0
		for ; i < length; i++ {
			if ss[0][i] != v[i] {
				if i == 0 {
					// 如果两个元素第一个字符就不同,那么就不用比较了,直接返回""
					return ""
				} else {
					// 如果不是第一个字符不同,那么前面i个字符就是相同的
					break
				}
			}
		}
		// for循环结束后,一定有i个字符是相同的,在此以i为临界点切割ss[0],再进行下一次比较
		ss[0] = ss[0][:i]
	}
	return ss[0]
}
```
