### 解题思路
此处撰写解题思路
golang回溯解法。题目中说是要去重，但是答案貌似没有去重。

### 代码

```golang
func backTrack(i, numsLen , k int, nums []int, curr *[]int, res *[][]int){
	if i <= numsLen && len(*curr) == k{
		temp := make([]int, len(*curr))
		for idx, v := range *curr{
			temp[idx] = v
		}
		*res = append(*res, temp)
		return
	}

	for j := i; j < numsLen; j++{
		// append
		*curr = append(*curr, nums[j])

		// back
		backTrack(j+1, numsLen, k, nums, curr, res)

		// pop
		*curr = (*curr)[:len(*curr)-1]
	}
}

func subsets(nums []int) [][]int {
	var numsLen int
	result := make([][]int, 0)

	numsLen = len(nums)
	for num := 0; num <= numsLen; num++{
		backTrack(0, numsLen, num, nums, &[]int{}, &result)
	}
	
	return result
}

```