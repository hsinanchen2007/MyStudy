###解题思路
1.使用for循环进行遍历
2.条件该如何设定
3.如何在数组中插入元素的方法

```
func searchInsert(nums []int, target int) int {
	for i, v := range nums {
		if v == target {
			return i
		}
		if v > target {
			nums = append(nums[:i], append([]int{target}, nums[i:]...)...)
			return i
		}
	}
	nums = append(nums, target)
	return len(nums) - 1

}
```
![2.png](https://pic.leetcode-cn.com/6246fa7e82696b4dc9d50ce53097a12a3c9e7d37bf8a541da7be60e262612716-2.png)
