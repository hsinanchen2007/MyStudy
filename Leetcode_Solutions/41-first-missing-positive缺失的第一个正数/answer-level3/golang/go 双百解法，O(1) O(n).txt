### 解题思路
官方思路实现 

### 代码

```golang
func firstMissingPositive(nums []int) int {
	// 如果只有1就返回2
	if len(nums) == 1 {
		if nums[0] == 1 {
			return 2
		} else {
			return 1
		}
	}

	// 如果没有1返回1成功
	var flag_one int
	for _, v := range nums {
		if v == 1 {
			flag_one = 1
		}
	}
	if flag_one == 0{
		return 1
	}

	// 把所有的负数和大于n的数字置1
	for k, v := range nums {
		if v <= 0{
			nums[k] = 1
		}
		if v > len(nums) {
			nums[k] = 1
		}
	}

	// 把所有的出现数字中对应的value值乘以-1，代表这个数字出现了
	for _, v := range nums {
		if int(math.Abs(float64(v))) == len(nums) {
			nums[0] = int(math.Abs(float64(v)))
		} else if nums[int(math.Abs(float64(v)))] > 0 {
			nums[int(math.Abs(float64(v)))] *= -1
			if nums[0] < int(math.Abs(float64(v))) {
				nums[0] = int(math.Abs(float64(v)))
			}
		}
	}

	// 返回结果
	for i:=1; i<len(nums); i++ {
		if nums[i] > 0 {
			return i
		}
	}
	return nums[0] + 1
}

```