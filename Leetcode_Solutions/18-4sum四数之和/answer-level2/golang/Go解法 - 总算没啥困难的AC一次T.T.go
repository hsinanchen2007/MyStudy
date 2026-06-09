这题库有毒，做完三数之和，做三数之和的最接近值，又做这个
```
 func fourSum(nums []int, target int) [][]int {
 	//排序
 	sort.Ints(nums)
 	var rs [][]int

 	if len(nums) < 4 {
 		return rs
	}

 	for i := 0;i < len(nums) - 3;i++ {
 		if i > 0 && nums[i - 1] == nums[i] {
 			continue
		}

 		for j := i + 1;j < len(nums) - 2;j++ {
			if j > i + 1 && nums[j - 1] == nums[j] {
				continue
			}

			l := j + 1
			r := len(nums) - 1
			for l < r {
				if nums[i] + nums[j] + nums[l] + nums[r] > target {//大
					for l < r && nums[r-1] == nums[r] {
						r--
					}
					r--
				} else if nums[i] + nums[j] + nums[l] + nums[r] < target {//小
					for l < r && nums[l+1] == nums[l] {
						l++
					}
					l++
				} else {//这里不能直接退出，剩余数据中仍可能有解
					rs = append(rs, []int{nums[i], nums[j], nums[l], nums[r]})
					for l < r && nums[l+1] == nums[l] {
						l++
					}
					l++
					for l < r && nums[r-1] == nums[r] {
						r--
					}
					r--
				}
			}
		}
	}

 	return rs
 }
```