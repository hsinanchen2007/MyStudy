先排序，然后进行排序。当 i 小于 n-1 时，通过 i+1,n-1 两个指针从两边向中间移动，直到两个指针重合。
每次移动后判断 当前位置和两个指针位置的数字之和，如果大于零，则将后面的指针向前移，否则反之。如果正好等于零，则记录三个数 并两个指针同时在自己的方向上移动。

代码：
```go [go]

func threeSum(nums []int) [][]int {
	var result = make([][]int, 0)

	if len(nums) < 3 {
		return result
	}
	quickSort(nums)

	for i := 0; i < len(nums)-1; i++ {
		var (
			head, end = i + 1, len(nums) - 1
		)
		if nums[i] > 0 || nums[head]+nums[i] > 0 {
			break
		}
        
		if i > 0 && nums[i] == nums[i-1] { // 去重
			continue
		}

		for head < end {
			if head > i+1 && nums[head] == nums[head-1] { // 去重
				head++
				continue
			}

			if end < len(nums)-2 && nums[end] == nums[end+1] { // 去重
				end--
				continue
			}

			sum := nums[i] + nums[head] + nums[end]
			if sum > 0 {
				end--
				continue
			}

			if sum < 0 {
				head++
				continue
			}

			result = append(result, []int{nums[i], nums[head], nums[end]})
			head++
			end--
		}

	}

	return result
}

// 快排
func quickSort(nums []int) {
	ln := len(nums)
	if ln < 2 {
		return
	}

	var (
		cur       = nums[0]
		head, end = 0, ln - 1
	)

	for i := 1; i <= end; {
		if nums[i] < cur {
			// swap
			nums[head], nums[i] = nums[i], nums[head]
			head++
			i++
		} else {
			nums[end], nums[i] = nums[i], nums[end]
			end--
		}
	}

	quickSort(nums[:head])
	quickSort(nums[head+1:])
}
```