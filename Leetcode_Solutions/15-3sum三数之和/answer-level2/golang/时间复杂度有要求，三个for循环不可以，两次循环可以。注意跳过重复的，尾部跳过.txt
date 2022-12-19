### 解题思路
此处撰写解题思路

### 代码

```golang


func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	rlt := [][]int{}
	var last []int
	for index := 0; index < len(nums)-2; index++ {
		value := nums[index]
		left := index + 1
		right := len(nums)-1
		for left < right {
			if value + nums[left] + nums[right] == 0 {
				if len(last) == 0 {
					rlt = append(rlt, []int{value, nums[left], nums[right]})
				} else {
					if !(last[0] == value && last[1] == nums[left]) {
						rlt = append(rlt, []int{value, nums[left], nums[right]})
					}
				}
				last = []int{value, nums[left], nums[right]}
				left += 1
				right -= 1
			} else if value + nums[left] + nums[right] > 0 {
				right -= 1
			} else {
				left += 1
			}
		}
		for index < len(nums)-2 && value == nums[index+1] {
			index += 1
		}
	}
	return rlt
}
```