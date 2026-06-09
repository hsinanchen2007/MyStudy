### 解题思路
参考三数之和的思路，在外边加一个循环即可。
因为要求不重复的四元组，注意剪枝

### 代码

```golang

func threeSum(nums []int, target int) [][]int {

	var buf [][]int
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		start, end := i+1, len(nums)-1
		for start < end {
			if start > i+1 && start < len(nums) && nums[start] == nums[start-1] {
				start++
				continue
			}
			if end < len(nums)-1 && end >= start && nums[end] == nums[end+1] {
				end--
				continue
			}
			if nums[i]+nums[start]+nums[end] > target {
				end--
			} else if nums[i]+nums[start]+nums[end] < target {
				start++
			} else {
				buf = append(buf, []int{nums[i], nums[start], nums[end]})
				start++
				end--
			}
		}
	}

	return buf
}

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	fmt.Println(nums)
	var ret [][]int
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		fmt.Println(nums[i], target-nums[i])
		r := threeSum(nums[i+1:], target-nums[i])
		for j := 0; j < len(r); j++ {
			ret = append(ret, append(r[j], nums[i]))
		}
	}

	return ret
}

```