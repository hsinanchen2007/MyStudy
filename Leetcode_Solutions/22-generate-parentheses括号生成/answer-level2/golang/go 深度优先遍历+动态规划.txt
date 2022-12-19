

```
//动态规划
func generateParenthesis(n int) []string {
	maps := make([][]string,n+1)
	maps[0] = []string{""}
	for i:= 1;i <= n;i++{
		maps[i] = []string{}
		for j:= 0; j< i;j++{
			l,r := j,i-1-j
			for _,v1:= range maps[l]{
				for _,v2 := range maps[r]{
					maps[i] = append(maps[i],"("+v1+")"+v2)
				}
			}
		}
	}
	return maps[n]
}
```



```
//深度优先遍历 从最大开始
func generateParenthesis(n int) []string {
	res := []string{}
	if n == 0{
		return res
	}
	dfs("",n,n,&res)
	return res
}
func dfs(ss string,left,right int, res *[]string)  {
	if left == 0 && right == 0{
		*res = append(*res,ss)
		return
	}
	if left  > right{
		return
	}
	if left > 0{
		dfs(ss +"(",left-1,right,res)
	}
	if right > 0{
		dfs(ss +")",left,right-1,res)
	}
}

//深度优先遍历 从小开始
func generateParenthesis(n int) []string {
	res := []string{}
	if n == 0{
		return res
	}
	dfs("",0,0,n,&res)
	return res
}
func dfs(ss string,left,right,n int, res *[]string)  {
	if left == n  && right == n {
		*res = append(*res,ss)
		return
	}
	if left  < right{
		return
	}
	if left < n{
		dfs(ss +"(",left+1,right,n,res)
	}
	if right < n{
		dfs(ss +")",left,right+1,n,res)
	}
}
```
