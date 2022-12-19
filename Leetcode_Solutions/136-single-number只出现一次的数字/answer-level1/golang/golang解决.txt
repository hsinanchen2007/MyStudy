设n个数字其中两个数字必然重复即2n个数字重复,有1个不重复数字即2n+1个奇数一共，排序后使用步进二的数值进行循环，比较这两个数字，如果相等则pass，如果不等则判断数字左右关系，可以使用递归写，这里给出迭代：
func singleNumber(nums []int) int {

	sort.Ints(nums)
	numsLen := len(nums)
	count := -1
	for {
		count += 2
		if count <= numsLen-2 {
			if nums[count-1] != nums[count] {
				if nums[count] == nums[count+1] {
					return nums[count-1]
				} else {
					return nums[count]
				}
			}

		} else {
			return nums[numsLen-1]
		}

	}

}
