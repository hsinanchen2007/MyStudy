首先对数据进行排序，使得数组从小到大进行排序
然后进行迭代匹配，以遍历数组的key为基础，新增一对双指针进行内部遍历。


```
func threeSum(nums []int) [][]int {
	if nums == nil || len(nums) < 3 { // 初始化校验
		return nil
	}
	sort.Ints(nums) // 对数据进行排序，使得数组是从小到大进行排序
	len := len(nums)
	var res [][]int

	for i := 0; i < len-1 ; i++ {
		if nums[i] > 0 { // 如果排序后第一个数就 > 0，则本题无解
			break
		}
		if i > 0 && nums[i] == nums[i-1] { // 去重提高效率
			continue
		}

		l, r := i + 1, len - 1
		for l < r {
			sum := nums[i] + nums[l] + nums[r]
			switch {
			case sum > 0:  // 总数太大，则右边往左一位，用更小的数进行匹配
				r --
			case sum < 0:  // 总数太小，则左边往右一位，用更大的数进行匹配
				l ++
			case sum == 0: // 总数符合条件，加入到结果数组中
				res = append(res, []int{nums[i], nums[l], nums[r]})
				for l < r {
					if nums[l] == nums[l+1] {
						l ++
						continue
					}
					if nums[r] == nums[r-1] {
						r --
						continue
					}
					break
				}
				l ++
				r --
			}
		}

	}
	return res
}
```
