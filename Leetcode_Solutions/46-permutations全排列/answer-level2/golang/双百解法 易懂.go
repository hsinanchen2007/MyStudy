### 解题思路
看注释

### 代码

```golang
func dfs(nums []int, path []int, res *[][]int) {
    if len(nums)==1 {
        path = append(path, nums[0])//长度为1 代表最后一个值了，添加到path直接返回
        *res = append(*res, path)
        return
    }
    //循环nums 
    for i := 0; i < len(nums); i++ {
        nums[0],nums[i] = nums[i],nums[0]//将i 和第一个元素进行交换
        dfs(nums[1:],append(path, nums[0]),res)//将i后面的元素递归，传入结果集和目前的路径
        nums[0],nums[i] = nums[i],nums[0]//复原
    }
}
func permute(nums []int) [][]int {
    var res [][]int
    if len(nums)==0 {
        return res
    }
    dfs(nums,nil,&res)
    return res
}
```

### 结果
执行用时 :
0 ms
, 在所有 Go 提交中击败了
100.00%
的用户
内存消耗 :
2.6 MB
, 在所有 Go 提交中击败了
100.00%
的用户