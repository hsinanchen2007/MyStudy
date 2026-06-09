直接调用标准库sort.SearchInts()。

```
执行用时 : 4 ms, 在Search Insert Position的Go提交中击败了99.42% 的用户
内存消耗 : 3.1 MB, 在Search Insert Position的Go提交中击败了53.57% 的用户
```
```Go []
func searchInsert(nums []int, target int) int {
	return sort.SearchInts(nums, target)
}
