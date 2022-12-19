```
// moveZeroes1
// 用两层循环
// 第一层循环将非零数放到数组前面
// 第二层循环将后面补零
func moveZeroes1(nums []int) {
	j := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 {
			nums[j] = nums[i]
			j++
		}
	}
	for ; j < len(nums); j++ {
		nums[j] = 0
	}
}

// moveZeroes2
//利用双指针，遇到零就和后面的非零数进行交换
func moveZeroes2(nums []int) {
	i, j := 0, 0
	for j < len(nums) {
		nums[i], nums[j] = nums[j], nums[i]
		if nums[i] != 0 {
			i++
		}
		j++
	}
}

// moveZeroes3
// 利用双指针，遇到零就和后面非零数进行交换，
func moveZeroes3(nums []int) {
	j := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			continue
		}
		nums[j] = nums[i]
		if i != j {
			nums[i] = 0
		}
		j++
	}
}
```
