```
func fourSum(nums []int, target int) [][]int {
    sort.Sort(sort.IntSlice(nums)) // 从小到大排序
    
    ret := make([][]int,0) 
     
    for i := 0; i < len(nums)-3; i++ {
        // if nums[i] > target { break }
        if i > 0 && nums[i] == nums[i-1] { continue } // i去重
        
        threeRet := threeSum(nums[i+1:len(nums)], target-nums[i])
        if len(threeRet) == 0 { continue }
        for _, value := range threeRet {
            tmp := make([]int,3)
            copy(tmp,value)
            tmp = append(tmp, nums[i])
            ret = append(ret, tmp)
        }  
    }
    
    return ret
}


func threeSum(nums []int, target int) [][]int {
    if len(nums) < 3 { return [][]int{} }

	ret := make([][]int, 0, 0)
	// 从最左侧开始固定，l r为固定i后开始对右侧部分遍历
	for i := 0; i < len(nums) - 1; i++ {
		l, r := i + 1, len(nums) - 1

		// if nums[i] > target || nums[i] + nums[l] > target { break }	// 优化掉不可能的情况

		if i > 0 && nums[i] == nums[i-1] { continue }	// i 去重 如果nums[i-1]时已考虑了nums[i]的全部情况

		for l < r {
			if l > i + 1 && nums[l] == nums[l-1] {	// l 去重
				l++; continue
			}
			if r < len(nums) - 2 && nums[r] == nums[r+1] {	// r 去重
				r--; continue
			}

			if nums[i] + nums[l] + nums[r] > target {	//
				r--
			} else if nums[i] + nums[l] + nums[r] < target {
				l++
			} else {
				ret = append(ret, []int{nums[i], nums[l], nums[r]})
				l++; r--
			}
		}
	}
	return ret
}
```