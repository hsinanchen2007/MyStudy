1.分治
```
func subsets(nums []int) [][]int {
    res := [][]int{}

    if nums == nil {
        return res
    }

    dfs(0, nums, []int{}, &res)

    return res
}

func dfs(index int, nums, arr []int, res *[][]int) {
    //terminator
    if index == len(nums) {
        *res = append(*res, arr)
        return
    }

    //process(split your big problem)
    //drill down(subproblems), merge(subsult)
    dfs(index+1, nums, arr, res)   //not select

    arr = append(arr, nums[index]) //select
    dfs(index+1, nums, arr, res)

    //revert current state
    arr = arr[:0]
}
```
2.迭代
```
func subsets(nums []int) [][]int {
    res := [][]int{{}}

    for i := 0; i < len(nums); i++ {
        newsets := [][]int{}
        for j, _ := range res {
            new_subset := res[j]
            new_subset = append(new_subset, nums[i])
            newsets = append(newsets, new_subset)
        }
        res = append(res, newsets...)
    }

    return res
}
```