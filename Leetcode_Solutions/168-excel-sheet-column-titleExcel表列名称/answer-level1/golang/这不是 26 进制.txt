10 进制是 0-9 ，
这里的取值范围是：1-26
所以如果一个 N <= 26，那么 N-1 才是 26 进制，所以代码可以这么写：

```
func convertToTitle(n int) string {
	var (
		rst []byte
	)
	for n > 0 {
		rst = append([]byte{'A' + uint8((n-1)%26)}, rst...)
		n = (n - 1) / 26
	}
	return string(rst)
}
```
