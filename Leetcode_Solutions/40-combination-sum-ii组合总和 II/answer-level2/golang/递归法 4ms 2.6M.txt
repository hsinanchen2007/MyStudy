### 解题思路

### 代码

```golang
func combinationSum2(candidates []int, target int) [][]int {
    // 特殊情况判断
	if len(candidates) == 0 {
		return nil
	}
	// 将 candidates 排序
	sort.Ints(candidates)
	// 返回结果
	var result [][]int
	helper(candidates, []int{}, target, &result)
	return result
}
func helper(arr, last []int, target int, ans *[][]int) {
	// 返回条件
	if target == 0 {
		*ans = append(*ans, last)
		return
	}
	if len(arr) > 0 && target < arr[0] {
		return
	}
	// 递归
	for idx := range arr {
		if idx > 0 && arr[idx] == arr[idx-1] {
			continue
		}
		cur := arr[idx]
		if cur <= target {
			// 判断是否不小于上一个数，以免重复
			if len(last) > 0 && cur < last[len(last)-1] {
				continue
			}
			// 将当前元素加入结果集
			var tmp []int
			tmp = append(last, arr[idx])
			// 递归
			helper(arr[idx+1:], tmp, target-cur, ans)
		}
	}
}
```