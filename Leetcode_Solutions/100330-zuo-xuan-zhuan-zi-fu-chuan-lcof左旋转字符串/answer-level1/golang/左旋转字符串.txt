### 解题思路
只需一行代码

### 代码

```golang
func reverseLeftWords(s string, n int) string {
	return s[n:] + s[:n]
}
```