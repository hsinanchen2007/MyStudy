### 解题思路
golang 是支持字符串的切片操作的，重新拼接两个字符串即可

### 代码

```golang
func reverseLeftWords(s string, n int) string {
	return s[n%len(s):]+s[:n%len(s)]
}
```