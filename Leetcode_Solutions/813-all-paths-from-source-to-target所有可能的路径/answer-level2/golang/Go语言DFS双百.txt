Go的实现
```golang
func allPathsSourceTarget(graph [][]int) [][]int {
	var res [][]int
	path:=[]int{0}
	dfs797(graph,&path,&res)
	return res
}

func dfs797(graph [][]int,path *[]int,res *[][]int){
	temp:=(*path)[len(*path)-1]
	if temp==len(graph)-1{
		cpy:=make([]int,len(*path))
		copy(cpy,*path)
		*res=append(*res,cpy)
		return
	}
	if len(graph[temp])==0{
		return
	}
	for _,v:=range graph[temp]{
		*path=append(*path,v)
		dfs797(graph,path,res)
		*path=(*path)[:len(*path)-1]
	}
}
```