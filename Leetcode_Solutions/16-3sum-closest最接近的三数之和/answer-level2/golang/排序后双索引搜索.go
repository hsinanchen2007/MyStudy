### 解题思路
此处撰写解题思路

### 代码

```golang

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	rltSum := nums[0] + nums[1] + nums[2]
	for i := 0; i < len(nums)-2; i++ {
		value := nums[i]
		left := i+1
		right := len(nums)-1
		for left < right {
			if math.Abs(float64(value + nums[left] + nums[right] - target)) < math.Abs(float64(rltSum - target)) {
				rltSum = value + nums[left] + nums[right]
			}
			if value + nums[left] + nums[right] - target == 0 {
				return target
			} else if value + nums[left] + nums[right] - target > 0 {
				right -= 1
			} else {
				left += 1
			}
		}
	}
	return rltSum
}
```