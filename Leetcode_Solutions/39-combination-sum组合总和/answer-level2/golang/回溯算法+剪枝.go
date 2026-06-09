

```
// 全排列，剪去不符合条件的分支
// 参考 回溯算法+剪枝
func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	//sort.Sort(sort.Reverse(sort.IntSlice(candidates))) // 降序
	res := [][]int{}
	step := func(path []int, node int) {}

	step = func(path []int, node int) {
		if node < 0 {
			return
		}
		if node == 0 {
			tmp := make([]int, len(path))
			copy(tmp, path)
			res = append(res, tmp)
		}

		for i := 0; i < len(candidates); i++ {
            // 大于node的待减值不符合条件
			if candidates[i] > node {
				return
			}
            // 剪枝：去除本次减法值比上一次减值小的情况，按照待减值递增原则排除[2,3,2]和[3, 2, 2]情况，只保留[2, 2, 3]
			if len(path) != 0 && path[len(path)-1] > candidates[i] {
				continue
			}
            // 继续递归调用
			step(append(path, candidates[i]), node - candidates[i])
		}
	}
	step([]int{}, target)

	return res
}

```