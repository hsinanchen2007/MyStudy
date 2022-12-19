### 解题思路
如题，是因为测试用例太少，还是Go语言底层对字符串比较做了优化？

执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.3 MB, 在所有 Go 提交中击败了67.24%的用户

### 代码

```golang
func strStr(haystack string, needle string) int {
	n := len(needle)
	for i := 0; i <= len(haystack)-n; i++ {
		if haystack[i:i+n] == needle {
			return i
		}
	}
	return -1
}
```