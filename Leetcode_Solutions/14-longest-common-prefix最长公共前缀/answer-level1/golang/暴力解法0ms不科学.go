### 解题思路
是测试用例太少的缘故吗？明明是很low的解法，居然这么快，不科学。

执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.4 MB, 在所有 Go 提交中击败了93.69%的用户

### 代码

```golang
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	if len(strs) == 1 {
		return strs[0]
	}
	res := ""
	for i := 0; i < len(strs[0]); i++ {
		for j := 1; j < len(strs); j++ {
			if len(strs[j]) <= i || strs[j][i] != strs[0][i] {
				return res
			}
		}
		res += strs[0][:i+1]
	}
	return res
}
```