调用标准库strconv.FormatInt()。
```
执行用时 : 0 ms, 在Base 7的Go提交中击败了100.00% 的用户
内存消耗 : 2 MB, 在Base 7的Go提交中击败了62.50% 的用户
```
```go []
func convertToBase7(num int) string {
	return strconv.FormatInt(int64(num), 7)
}
```