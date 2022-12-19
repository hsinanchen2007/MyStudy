func moveZeroes(nums []int)  {

	count := 0 // 记录0的个数
	for i, n := range nums {
		if n != 0 {
			nums[count], nums[i] = nums[i], nums[count]
            count++
		}
	}

	return

}