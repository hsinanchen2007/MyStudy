### 解题思路
此处撰写解题思路

### 代码

```golang
func subsets(nums []int) [][]int {
	item := make([]int, 0)
	result := make([][]int, 0)
	result= append(result, item)
	generate(0, nums, item, &result)
	return result
}

func generate(i int, nums, item []int, result *[][]int) {
	if i >= len(nums) {
		return
	}
	// 0 ，1选择，放还是不放
	// 放
	item = append(item, nums[i])
	itemcy:=make([]int, len(item))
	copy(itemcy,item)
	*result = append(*result, itemcy)
	generate(i+1, nums, item, result)


	// 不放
	item = item[:len(item)-1]
	generate(i+1, nums, item, result)
}

```