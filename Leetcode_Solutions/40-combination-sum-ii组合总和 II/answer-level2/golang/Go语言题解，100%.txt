```
import "sort"

var ans [][]int

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	ans = [][]int{}
	var res []int
	dfs(candidates, res, 0, 0, target)
	return ans
}

func dfs(candidates, res []int, index, cur, target int) {
	if cur == target {
		var tmp []int
		tmp = append(tmp, res...)
		ans = append(ans, tmp)
		return
	}
	if index >= len(candidates) || cur > target {
		return
	}
	for i := index; i < len(candidates); {
		if cur+candidates[i] > target {
			break
		}
		res = append(res, candidates[i])
		dfs(candidates, res, i+1, cur+candidates[i], target)
		res = res[:len(res)-1]
		for i+1 < len(candidates) && candidates[i] == candidates[i+1] {
			i++
		}
		i++
	}
}

```
