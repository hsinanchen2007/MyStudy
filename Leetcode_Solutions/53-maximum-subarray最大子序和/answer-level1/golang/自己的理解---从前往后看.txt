从前往后遍历，并且从前往后看累加的结果，
1。如果累加结果是个负数，那么没必要往后继续加了，
因为越加越少，这时候直接把累加结果重置为当前下标对应的值
2  如果累加结果是个正数或0，则继续累加

func maxSubArray(nums []int) int {
	if len(nums) <= 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	result := nums[0]
	sum := nums[0]
	for index := 1; index < len(nums); index++ {
		if sum >= 0 {
			sum = sum + nums[index]
			if sum > result {
				result = sum
			}
		} else {
			if nums[index] > sum {
				sum = nums[index]
				if sum > result {
					result = sum
				}
			}
		}
	}
	return result

}
