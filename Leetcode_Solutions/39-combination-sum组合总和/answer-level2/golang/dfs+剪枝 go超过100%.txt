### 解题思路
采用dfs+剪枝的方式，如candidates = [2,3,6,7], target = 7,如果选入2，则求剩下7-2=5是否有值。当剩余值target-candidates[i]==0,加入结果集；当target-candidates[i]<0,退出循环（剪枝）。在进行for循环时，引入begin是为了避免重复结果集。

### 代码

```golang
var res39 [][]int

func combinationSum(candidates []int, target int) [][]int {
	res39 = [][]int{}
	sort.Ints(candidates)
	dfs39(candidates, target, 0, []int{})
	return res39
}

func dfs39(candidates []int, target int, begin int, selected []int) {
	if target == 0 {
		res := make([]int, len(selected));
		copy(res, selected)//深拷贝，保证已加入结果集不受影响
		res39 = append(res39, res)
		return
	} else if target < 0 {
		return
	} else {
		for i := begin; i < len(candidates); i++ {
			if candidates[i] > target{//提前剪枝
				break
			}
			selected = append(selected, candidates[i])
			dfs39(candidates, target-candidates[i], i, selected)
			length := len(selected)
			if length > 0{
				selected = selected[0 : length-1]
			}	
		}
	}
}

```