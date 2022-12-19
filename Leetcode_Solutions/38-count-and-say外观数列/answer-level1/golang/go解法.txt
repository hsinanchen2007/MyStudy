首先评论里的老哥map天秀

思路很常规，大致是递归

首先给一个种子 `ret := "1"`

以这个种子开始，执行n-1次后就是需要的值

下面是代码

```go
func countAndSay(n int) string {
    n--
	ret := "1"
	for i := 0; i < n; i++ {
		var str []rune
		l := len(ret)
		count := 49
		for j := 0; j < l; j++ {
			if j+1 == l {
				str = append(str, rune(count), rune(ret[j]))
				count = 49
			} else {
				if ret[j] == ret[j+1] {
					count++
				} else {
					str = append(str, rune(count), rune(ret[j]))
					count = 49
				}
			}
		}
		ret = string(str)
	}
	return ret
}
```