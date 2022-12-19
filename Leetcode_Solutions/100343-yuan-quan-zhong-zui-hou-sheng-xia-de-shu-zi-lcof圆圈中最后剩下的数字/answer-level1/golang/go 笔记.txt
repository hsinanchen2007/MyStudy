[约瑟夫环](https://blog.csdn.net/u011500062/article/details/72855826)
```
func lastRemaining(n int, m int) int {
	f := 0
	for i := 2; i != n+1; i++ {
		f = (m + f) % i
	}
	return f
}
```
