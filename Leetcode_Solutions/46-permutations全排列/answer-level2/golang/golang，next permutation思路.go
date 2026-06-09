### 解题思路

根据https://www.nayuki.io/page/next-lexicographical-permutation-algorithm描述的next permutation算法实现

### 代码

```golang
// see https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
func nextPermutation(nums []int) ([]int, bool) {
	n := len(nums)

	// 1) find the longest non-increasing suffix and get pivot
	pivot := n - 2
	for ; pivot >= 0; pivot -= 1 {
		if nums[pivot] < nums[pivot+1] {
			break
		}
	}
	// if the permuate is total reverse order, it's done
	if pivot < 0 {
		return make([]int, n), false
	}

	// 2) find rightmost successor to pivot in the suffix
	successorIdx := pivot + 1
	successor := nums[pivot+1]
	for i := successorIdx + 1; i < n; i += 1 {
		if nums[i] > nums[pivot] && nums[i] < successor {
			successor = nums[i]
			successorIdx = i
		}
	}

	// 3) swap pivot and successor
	nums[pivot], nums[successorIdx] = nums[successorIdx], nums[pivot]

	// 4) reverse the suffix
	for i, j := pivot+1, n-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}

	return nums, true
}

func permute(nums []int) [][]int {
	result := make([][]int, 0)
	sort.Ints(nums)

	// output the first one
	p := make([]int, len(nums))
	copy(p, nums)
	result = append(result, p)

	// generate the follows
	for {
		nums, hasNext := nextPermutation(nums)
		if !hasNext {
			break
		}
		p := make([]int, len(nums))
		copy(p, nums)
		result = append(result, p)
	}

	return result
}
```