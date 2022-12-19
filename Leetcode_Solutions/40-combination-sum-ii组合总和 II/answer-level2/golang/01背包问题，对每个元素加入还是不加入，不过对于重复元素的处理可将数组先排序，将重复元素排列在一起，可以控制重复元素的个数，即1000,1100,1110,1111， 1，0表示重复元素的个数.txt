### 解题思路

01背包问题，对每个元素加入还是不加入，不过对于重复元素的处理可将数组先排序，将重复元素排列在一起，可以控制重复元素的个数，即1000,1100,1110,1111， 1，0表示重复元素的个数
### 代码

```golang
func combinationSum2(candidates []int, target int) [][]int {
	if len(candidates) == 0 {
		return nil
	}
	var result [][]int
	sort.Ints(candidates)
	var item []int
	generate(candidates, 0, target, item, &result)
	return result
}
func generate(candidates []int, i int, target int, item []int, result *[][]int) {
	
	if target == 0 {
		res := make([]int, len(item))
		copy(res, item)
		*result = append(*result, res)
	}
    if i >= len(candidates) || candidates[i] > target {
		return
	}
	// 当前选
	item = append(item, candidates[i])
	generate(candidates, i+1, target-candidates[i], item, result)
	// 当前不选
	for i+1 < len(candidates) && candidates[i] == candidates[i+1] {
		i++
	}
	item = item[:len(item)-1]
	generate(candidates, i+1, target, item, result)
}

```