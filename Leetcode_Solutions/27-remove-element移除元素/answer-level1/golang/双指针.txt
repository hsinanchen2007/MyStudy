### 解题思路
声明两个指针：
1. 一个指针 last 表示新数组的最后一个元素的索引，
2. 一个指针 i 正向遍历当前数组

当 nums[i] 与给定值 val 相等时，把当前数组「最后一个元素」赋给 nums[i]，然后 last 减一，也就是逻辑层面上舍弃掉后面的数组元素，因为都是我们不要的。

这样我们只需要关心 i 到 last 之间的元素即可。

### 代码

```golang
func removeElement(nums []int, val int) int {
	i := 0
	last := len(nums)
	for i < last {
		if nums[i] == val {
			if nums[last-1] != val {
				nums[i] = nums[last-1]
			}
			last--
		} else {
			i++
		}
	}

	return last
}
```