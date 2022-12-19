解法： 此题与上一题的区别在于，需要去重

去重的话，先需要知道，什么情况会发生重复
示例 [1,3,1,2] 如，当1与1交换则相当于重复

首先需要明白我们回溯求解具体步骤：
一、首index选择1，求后面的全排列。
二、依次让首index的值1与后面的数进行交换，交换后，再求后面的全排列。

这样在步骤二里面，如果是1和1交换，求剩余的全排列。这种情况的全排列，就与步骤一时的全排列完全重复。

因此，需要再上述步骤中，标记一个数是否以及被选择到1号位置过。如果以及选择到1号位置过，则不能重复。

代码：
```
func permuteUnique(nums []int) [][]int {
	res := [][]int{}
	backtrace(0, nums, &res)
	return res
}

func backtrace(first int, nums []int, res *[][]int) {
	if first == len(nums) {
		temp := make([]int, len(nums))
		copy(temp, nums)
		*res = append(*res, temp)
	}
	m := map[int]bool{}
	for i := first; i < len(nums); i++ {
		if m[nums[i]] {
			continue
		}
		m[nums[i]] = true
		nums[first], nums[i] = nums[i], nums[first]
		backtrace(first+1, nums, res)
		nums[first], nums[i] = nums[i], nums[first]
	}
}
```