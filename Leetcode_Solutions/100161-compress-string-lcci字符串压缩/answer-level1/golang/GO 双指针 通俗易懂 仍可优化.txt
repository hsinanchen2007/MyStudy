### 解题思路
使用双指针，遇到不同的就更新`slow`到`quick`，同时计算数字为`quick-slow`
### 代码

```golang
func compressString(S string) string {
	if len(S) <= 1 {
		return S
	}
	// 可使用Builder优化
	res := ""
	// 双指针
	slow, quick := 0, 0
	for quick < len(S) {
		if S[quick] != S[slow] {
			res += string(S[slow]) + strconv.Itoa(quick-slow)
			slow = quick
		}
        quick++
	}
	// 最后一次处理
	res += string(S[slow]) + strconv.Itoa(quick-slow)
	
	if len(res) >= len(S) {
		return S
	}
	return res
}
```