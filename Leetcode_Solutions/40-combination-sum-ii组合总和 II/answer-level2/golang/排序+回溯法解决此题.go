话不多说，直接上代码：

```
import "sort"

// 排序 + 回溯
func combinationSum2(candidates []int, target int) [][]int {
    sort.Ints(candidates)
    var ans [][]int
    backtrack(candidates, target, 0, []int{}, &ans)
    return ans
}

func backtrack(candidates []int, target, index int, path []int, ans *[][]int) {
    // 退出条件
    if target == 0 {
        *ans = append(*ans, path)
        return
    }
    n := len(candidates)
    for i := index; i < n; i++ {
        // 去除多余的重复项（调整当前层的选择进度即可，下层需要继续可选）
        rawI := i
        for i < n - 1 && candidates[i] == candidates[i+1] {
            i++
        }
        // 剪枝
        if candidates[i] > target {
            return
        }
        // 作出选择
        newPath := make([]int, len(path))
        copy(newPath, path)
        newPath = append(newPath, candidates[i])
        backtrack(candidates, target-candidates[i], rawI+1, newPath, ans)
        // 撤回选择

    }
}
```