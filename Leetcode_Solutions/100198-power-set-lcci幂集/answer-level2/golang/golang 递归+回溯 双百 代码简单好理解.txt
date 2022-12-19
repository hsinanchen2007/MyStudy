```
func subsets(nums []int) [][]int {
    // 结果集
    res := make([][]int, 0)    
    // 临时栈
    stack := make([]int, 0)

    var search func(depth int)
    search = func(depth int) {
        if depth == len(nums) {
            t := make([]int, len(stack))
            copy(t, stack)
            res = append(res, t)
            return
        }
        // 递归
        stack = append(stack, nums[depth])
        search(depth+1)
        // 回溯
        stack = stack[:len(stack)-1]
        search(depth+1)
    }

    search(0)
    return res
}
```
