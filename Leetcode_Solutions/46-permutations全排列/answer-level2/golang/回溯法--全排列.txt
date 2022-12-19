### 解题思路


### 代码

```golang
func permute(nums []int) [][]int {
    if nums == nil || len(nums) == 0{
        return nil
    }
    
    var result [][]int= make([][]int, 0, len(nums))
    var visited = make([]int, 0, len(nums))
    result = backtrack(nums, visited, result)
    return result
}
// backtrack: 从nums里面选择可以访问的数字，visited保留了之前访问过的数字，result保留了之前的全排列
// 返回值之所以又返回result，是因为slice在进行append操作的时候，地址可能会发生变更
func backtrack(nums []int, visited []int, result [][]int) [][]int{
        if len(nums) == 1 {
            visited = append(visited, nums[0])
            //注意slice需要使用拷贝，避免指向同一个底层数组，被修改
            //同时，注意目标slice的长度，不能是0
            tmp := make([]int, len(visited))
            copy(tmp, visited)
            result = append(result, tmp)
            return result
        }
        depth := len(visited)
        visited = append(visited, -1)
        for i := 0; i < len(nums); i++ {
            visited[depth] = nums[i]
            remainNums := []int{}
            remainNums = append(remainNums, nums[:i]...)
            remainNums = append(remainNums, nums[i+1:]...)
            result = backtrack(remainNums, visited, result)
        }
        return result
}

```