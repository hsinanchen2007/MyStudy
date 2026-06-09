### 解题思路
此处撰写解题思路

### 代码

```golang
func subsets(nums []int) [][]int {
    if nums == nil {
        return nil
    }
    var visited []int = make([]int, 0, len(nums))
    var result [][]int = make([][]int, 0, len(nums))
    //记录空集合
    result = append(result, []int{})
    //回溯法递归处理数组nums
    result = backtrace(nums, visited, result)
    return result
}

//backtrace：
//params:
//1. nums: 可以选择的数字列表
//2. visited：已经遍历过的数字列表
//3. result: 已有的集合
//returns:
//1. [][]int: 返回处理nums之后的集合result
func backtrace(nums []int, visited []int, result [][]int) [][]int {
    if len(nums) == 1 {
        visited = append(visited, nums[0])
        tmp := make([]int, len(visited))
        copy(tmp, visited)
        result = append(result, tmp)
        return result
    }
    last := len(visited)
    visited = append(visited, -1)
    for i := 0; i < len(nums); i++ {
        //在递归遍历每个节点的过程中，记录当前子集元素visited到结果result中
        visited[last] = nums[i]
        tmp := make([]int, len(visited))
        copy(tmp, visited)
        result = append(result, tmp)

        //前面已经出现遍历过的数字，后面不能再出现了
        remainNums := make([]int, 0, len(nums)-i)
        remainNums = append(remainNums, nums[i+1:]...)
        result = backtrace(remainNums, visited, result)
    }
    return result
}
```