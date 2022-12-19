### 解题思路
回溯算法很多时候都应用在“搜索”这类问题上。不过这里说的搜索，并不是狭义的指图的搜索算法，而是在一组可能的解中，搜索满足期望的解。

### 代码

```golang
func permute(nums []int) [][]int {
    len := len(nums)
    res := make([][]int, 0)
    path := make([]int, len)
    visited := make([]bool, len)
    backTrace(nums, len, 0, &res, path, visited)
    return res
}

func backTrace(nums []int, len int, idx int, res *[][]int, path []int, visited []bool) {
    if idx == len {
        tmp := make([]int, len)
        copy(tmp, path)
        *res = append(*res, tmp)
        return
    }
    for i:=0; i<len; i++ {
        if !visited[i] {
            path[idx] = nums[i]
            visited[i] = true
            backTrace(nums, len, idx+1, res, path, visited)
            visited[i] = false
        }
    }
    return
}
```