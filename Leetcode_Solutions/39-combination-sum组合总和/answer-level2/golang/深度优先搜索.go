### 解题思路

先排序，然后深度优先搜索，用一个变量记录搜索过的值，防止重复

### 代码

```golang
func combinationSum(candidates []int, target int) [][]int {
	var (
		ans    [][]int
		res    []int
		length = len(candidates)
		dfs    func(int)
		last   int
	)
	dfs = func(target int) {
		if target < 0 {
			return
		}
		if target == 0 {
			tmp := make([]int, len(res))
			copy(tmp, res)
			ans = append(ans, tmp)
		}
		for i := last; i < length; i++ {
			if target-candidates[i] >= 0 {
				last = i
				res = append(res, candidates[i])
				dfs(target-candidates[i])
				res = res[:len(res)-1]
				last = i
			}
		}
	}

	sort.Ints(candidates)
	dfs(target)
	return ans
}

```