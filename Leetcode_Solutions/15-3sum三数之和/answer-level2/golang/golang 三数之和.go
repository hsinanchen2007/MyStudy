```go

import "sort"

func threeSum(nums []int) [][]int {
	// 临界测试 [] [1,-1]
	if len(nums) < 2 {
		return [][]int{}
	}
	// 排序 O(NlogN)
	sort.Ints(nums)
	res := [][]int{}

	for i := range nums[:len(nums)-2] { // 后2个元素后的元素不足两个
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		l, r := i+1, len(nums)-1

		for l < r {
			sum := nums[i] + nums[l] + nums[r]
			switch {
			case sum < 0:
				l++
			case sum > 0:
				r--
			default:
				res = append(res, []int{nums[i], nums[l], nums[r]})
				l, r = next(nums, l, r)
			}
		}
	}
	return res
}

func next(nums []int, l int, r int) (int, int) {
	for l < r {
		switch {
		case nums[l] == nums[l+1]: // 跳过左指针的重复值
			l++
		case nums[r] == nums[r-1]: // 跳过右指针的重复值
			r--
		default:
			l++
			r--
			return l, r
		}
	}
	return l, r
}
```