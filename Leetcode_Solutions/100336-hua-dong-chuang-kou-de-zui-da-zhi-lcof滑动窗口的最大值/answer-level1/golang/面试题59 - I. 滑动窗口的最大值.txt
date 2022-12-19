### 解题思路
此处撰写解题思路

### 代码

```golang
func maxSlidingWindow(nums []int, k int) []int {
	if len(nums) == 0 || k <= 0 {
		return []int{}
	}

	left := 0
	right := k
	maxNum := []int{}
	for right <= len(nums) {
		tempMax := -math.MaxInt32
		for i := left; i < right; i++ {
			if nums[i] > tempMax {
				tempMax = nums[i]
			}
		}
		maxNum = append(maxNum, tempMax)
		left ++
		right ++

	}
	return maxNum

}
```