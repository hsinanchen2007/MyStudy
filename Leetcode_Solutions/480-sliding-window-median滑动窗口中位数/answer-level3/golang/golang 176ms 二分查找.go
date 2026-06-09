使用二分查找找到每一次要删的idx和要插入的idx即可

1. 先对前k个排序，计算中位数
2. 遍历后面的数
3. 二分查找到第一个数的位置，删除
4. 二分查找到需要插入数的位置，添加
5. 计算中位数
```
func medianSlidingWindow(nums []int, k int) []float64 {
	knums := make([]int, k)
	copy(knums, nums[:k])
	sort.Ints(knums)
	ret := make([]float64, len(nums) - k + 1)
	ret[0] = calMid(knums, k)
	for i := k; i < len(nums); i++ {
		delIdx := binarySearch(knums, nums[i-k])
		knums = append(knums[:delIdx], knums[delIdx+1:]...)
		addIdx := binarySearch(knums, nums[i])
		last := append([]int{nums[i]}, knums[addIdx:]...)
		knums = append(knums[:addIdx], last...)
		ret[i-k+1] = calMid(knums, k)
	}
	return ret
}

func binarySearch(nums []int, val int) int {
	low, high := 0, len(nums) - 1
	for low <= high {
		mid := low + (high - low)/2
		if nums[mid] == val {
			return mid
		} else if nums[mid] > val {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return low
}

func calMid(nums []int, k int) float64 {
	n1, n2 := 0, 0
	if k%2 == 0 {
		n1, n2 = nums[k/2-1], nums[k/2]
	} else {
		n1, n2 = nums[k/2], nums[k/2]
	}
	return float64(n1 + n2)/float64(2)
}
```
