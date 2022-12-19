### 解题思路
参考代码

这是一个偷懒的写法，因为数组已经排序，比较适合用二分法。

### 代码

```golang
func searchInsert(nums []int, target int) int {
    for k, v := range nums {
		if v >= target {
			return k
		}
	}
	return len(nums)
}
```