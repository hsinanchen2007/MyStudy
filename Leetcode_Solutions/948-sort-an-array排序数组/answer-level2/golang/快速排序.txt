只用了一个快排进行处理、对于快排的原理做一个回顾:快速排序是每次从当前数组中选择一个元素为基准点、对整个数组进行遍历、将大于该元素的值放在它右边、小于该元素的值放在它左边。然后再对左右子数组进行递归处理。
```
func sortArray(nums []int) []int {
	_quick_sort1(nums, 0, len(nums) - 1)
	return nums
}
//leetcode submit region end(Prohibit modification and deletion)
func _quick_sort1(arr []int, begin, end int)  {
	// terminal
	if begin >= end {
		return
	}
	// current logic
	//mid := (begin + end) >> 1
	mid := _partition(arr, begin, end)
	// drill down
	_quick_sort1(arr, begin, mid - 1)
	_quick_sort1(arr, mid + 1, end)
}

// 分区、返回基准索引p、使得arr[l:p - 1] < arr[p] && arr[p + 1: r] > arr[p]
func _partition(arr []int, l int, r int) int {
	p := l  // 取第一个元素为基点
	j := p + 1 // j 表示大于基点和小于基点的分界下标
	for i := l + 1; i <= r; i++ {
		if arr[i] < arr[p] {
			arr[i], arr[j] = arr[j], arr[i]
			j++
		}
	}
    // 整个数组遍历完成之后、j所指向的元素就是第一个大于arr[p]的元素、所以将p与j-1进行交换
    // 最后返回j - 1
	arr[p], arr[j - 1] = arr[j - 1], arr[p]
	return j - 1
}
```
