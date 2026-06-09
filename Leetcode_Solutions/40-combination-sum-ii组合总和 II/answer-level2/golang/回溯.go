### 解题思路
模板题
### 代码

```golang
func combinationSum2(candidates []int, target int) [][]int {
     sort.Ints(candidates)
     path:=make([]int,0)
     res:=make([][]int,0)
     b:=make([]bool,len(candidates))
    DFS(candidates ,target,path,&res,0,b )
     return res
}
func DFS(candidates []int,target int,path []int,res *[][]int,num int,b []bool){
    if target==0{
        *res=append(*res,append([]int{},path...))
        return 
    }
    for i:=num;i<len(candidates) &&target-candidates[i]>=0;i++{
        if b[i]==false{
            if i> num && candidates[i]==candidates[i-1]{
                    continue
            }
        path=append(path,candidates[i])
        b[i]=true
        DFS(candidates,target-candidates[i],path,res,i+1,b)
        path=path[:len(path)-1]
        b[i]=false
        }
       
    }
}
```