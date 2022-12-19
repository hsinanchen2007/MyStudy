### 解题思路
奥利给！干就完了！

### 代码

```golang
func findRepeatNumber(nums []int) int {
	// 1.长度为0
	if len(nums) == 0 {
		return 0
	}
	// 2.开始遍历
	for i := 0; i < len(nums); i++ {
		// 3.如果nums[i] == i
		if nums[i] == i {
			continue
		} else {
			//4.互不相等
			for nums[i] != i{
				// 重了
				if nums[i] == nums[nums[i]] {
					return nums[i]
				}else{
					// 交换
					nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
				}
			}
		}
	}
	return -1
}

```