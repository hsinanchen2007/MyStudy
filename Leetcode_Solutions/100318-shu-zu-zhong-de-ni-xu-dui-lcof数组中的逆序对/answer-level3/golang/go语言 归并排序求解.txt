### 解题思路

分治法求解

### 代码

```golang
func reversePairs(nums []int) int {
	// TODO: 分治的思想
	cnt := 0
	var merge func([]int, []int) []int
	var mergeSort func([]int) []int

	mergeSort = func(nums []int) []int {
		if len(nums) < 2 {
			return nums
		}
		n := len(nums)
		mid := n >> 1
		left := mergeSort(nums[:mid])
		right := mergeSort(nums[mid:])
		return merge(left, right)
	}

	merge = func(ar1, ar2 []int) []int {
		var res = make([]int, 0)
		sz1, sz2 := len(ar1), len(ar2)
		i, j  := 0, 0
		for i < sz1 && j < sz2 {
			if ar1[i] <= ar2[j] {
				res = append(res, ar1[i])
				i++
			} else {
				res = append(res, ar2[j])
				cnt = cnt + sz1 - i
				j++
			}
		}
		for i < sz1 {
			res = append(res, ar1[i])
			i++
		}
		for j < sz2 {
			res = append(res, ar2[j])
			j++
		}
        return res
	}

	mergeSort(nums)
	return cnt
}

```