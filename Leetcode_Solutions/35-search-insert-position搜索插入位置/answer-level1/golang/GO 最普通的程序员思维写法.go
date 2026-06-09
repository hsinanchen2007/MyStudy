
没啥高大上的……这题很简单，都不需要用到算法也可以做完。


执行用时 : 4 ms, 在所有 Go 提交中击败了98.89%的用户
内存消耗 :3.2 MB, 在所有 Go 提交中击败了36.11%的用户

```go 
func searchInsert(nums []int, target int) int {
	sortNum := 0
	if len(nums) > 0 && target > 0 {
		for k, num := range nums {
			if num == target {
				return k
			} else if num < target {
				sortNum = k + 1
			}
		}
	}
	return sortNum
}
```
