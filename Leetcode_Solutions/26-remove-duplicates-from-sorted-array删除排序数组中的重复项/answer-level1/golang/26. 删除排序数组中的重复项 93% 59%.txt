### 解题思路
算法：虚拟数组，顺序遍历。可以想象一个虚拟数组，一旦发现不重复元素则填充进虚拟数组，该数组直接在原数组基础上填充，index为元素索引。显而易见不会覆盖掉原数组第一个非重复元素。
如果出现重复那么位置必定是连续两个元素，发现重复则原地删除该元素:记录第一个重复元素值val以及新数组虚拟位置index，直到发现不等于val，则填入nums[index]。

### 代码

```golang
func removeDuplicates(nums []int) int {
	// 记录第一个重复元素值val以及位置index
	if nums == nil || len(nums) <= 1 {
		return len(nums)
	}
	// index为逻辑数组索引，从1开始
	val, index := nums[0], 1
	for _, num := range nums {
		if num != val {
			nums[index] = num
			val = num
			index++
		}
	}
	return index
}
```