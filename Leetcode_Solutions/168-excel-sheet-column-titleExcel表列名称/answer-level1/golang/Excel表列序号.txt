### 解题思路
十进制转二十六进制

### 代码

```golang
func convertToTitle(n int) string {
    result := ""
	for n > 0 {
		m := n % 26
		if m == 0 {
			m = 26
			n -= 1
		}
        n = n / 26
		result = string(m+64)+result
	}
	return result
}
```