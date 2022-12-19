思路：双指针，快指针找下一个非重复元素，满指针更新前面的数组。
```
func removeDuplicates(nums []int) int {
	numLen := len(nums)
	var curIndex, endIndex int
	var target int
	for ; endIndex < numLen; curIndex++ {
		// 记录本轮要移动的元素
		target = nums[endIndex]
		// 找到本轮移动元素的下一个元素坐标
		for endIndex < numLen && nums[endIndex] == target {
			endIndex++
		}
		// 更新前面的数组，实现去重
		nums[curIndex] = target
	}
	return curIndex
}
```
![image.png](https://pic.leetcode-cn.com/4a501dab5e96a29d02909ae7e7fbc16b447fd12b0489323c9269ea08c4e034a7-image.png)
