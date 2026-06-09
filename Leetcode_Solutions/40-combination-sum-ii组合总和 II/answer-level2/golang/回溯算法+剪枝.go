```
func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	res := [][]int{}
	step := func(path []int, node int, index int) {}

	step = func(path []int, node int, index int) {
		if node < 0 {
			return
		}
		if node == 0 {
			tmp := make([]int, len(path))
			copy(tmp, path)
			res = append(res, tmp)
		}
        var mem = -1
		for i := index; i < len(candidates); i++ {
            // 剪枝提出重复的
            if candidates[i] == mem {
				continue
			} else {
				mem = candidates[i]
			}
			if candidates[i] > node {
				return
			}

			step(append(path, candidates[i]), node - candidates[i], i+1)
		}
	}
	step([]int{}, target, 0)

	return res
}
```