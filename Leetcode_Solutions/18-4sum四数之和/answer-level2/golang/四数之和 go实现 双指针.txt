运行时间击败 76% 😅
内存击败 100%

思路：
- 与三数之和基本类似，排序+双指针，多一层循环。
- 每次循环之前尽可能排除一些特殊情况 减少循环次数

```go [go]

func fourSum(nums []int, n int) [][]int {
	ln := len(nums)
	if ln < 4 {
		return nil
	}

	quickSort(nums)
	fmt.Println(nums)

	var result = make([][]int, 0)

	for i := 0; i < len(nums)-2; i++ {
		if n > 0 && nums[i] > n { // 排除不可能的情况
			break
		}

		if i > 0 && nums[i] == nums[i-1] { // 去重
			continue
		}

		for j := i + 1; j < len(nums)-1; j++ {
			var (
				head, end = j + 1, ln - 1
			)

			if nums[i]+nums[j]+nums[head] > n && nums[head] > 0 { // 排除不可能的情况
				continue
			}

			if j > i+1 && nums[j] == nums[j-1] { // 去重
				continue
			}

			for head < end {
				if head > j+1 && nums[head] == nums[head-1] { // 去重
					head++
					continue
				}

				if end < ln-2 && nums[end] == nums[end+1] { // 去重
					end--
					continue
				}

				sum := nums[i] + nums[j] + nums[head] + nums[end]
				if sum > n {
					end--
					continue
				}

				if sum < n {
					head++
					continue
				}

				result = append(result, []int{nums[i], nums[j], nums[head], nums[end]})
				head++
				end--
			}
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
		tag        = nums[0]
		head, tail = 0, ln - 1
	)

	for i := 1; i <= tail; {
		if nums[i] < tag {
			nums[head], nums[i] = nums[i], nums[head]
			head++
			i++

			continue
		}

		nums[tail], nums[i] = nums[i], nums[tail]
		tail--
	}

	quickSort(nums[:head])
	quickSort(nums[head+1:])
}

```

> 还有优化空间，望大佬们指点，🙏