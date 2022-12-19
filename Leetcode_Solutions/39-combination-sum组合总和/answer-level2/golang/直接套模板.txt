### 解题思路
  看样例发现结果不是固定的数组长度，所以需要指定开始回溯的下标
这类题的模板
for i:=start;i<遍历的长度;i++{
    if  判断条件{
        path=append(path,遍历的值)
            dfs(传入各种参数)
            path=path[:len(path)-1]
    }
}
### 代码

```golang
func combinationSum(candidates []int, target int) [][]int {
    res:=make([][]int,0)
    path:=make([]int,0)
        dfs(candidates,target,path,&res,0)
    return res
}
func dfs(candidates []int,target int, path []int, res *[][]int,st int){
    if target==0{
        *res=append(*res,append([]int{},path...))
    }
    for i:=st;i<len(candidates);i++{
        if target-candidates[i]>=0{
            path=append(path,candidates[i])
            dfs(candidates,target-candidates[i],path,res,i)
            path=path[:len(path)-1]
        }
    }
}
```