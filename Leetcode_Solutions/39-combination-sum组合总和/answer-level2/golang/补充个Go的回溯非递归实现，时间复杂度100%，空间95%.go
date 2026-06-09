不知道为啥脑子抽了要跑去写非递归实现
最后实现的代码非常乱，感觉只剩下代码的执行效果不错这一点了
放上来仅作参考，也不推荐各位去读
```
func combinationSum(candidates []int, target int) [][]int {
	var ans [][]int
	sort.Ints(candidates)
	var res,path []int
	temp,j:=0,0
	for j<len(candidates){
		if temp+candidates[j]<target {
			path=append(path,j)
			res=append(res,candidates[j])
			temp+=candidates[j]
			continue
		}
		if temp+candidates[j]==target {
			res=append(res,candidates[j])
			cpy:=make([]int,len(res))
			copy(cpy,res)
			ans=append(ans, cpy)
			if len(path)==0 {
				return ans
			}
			res=res[0:len(res)-1]
			j=path[len(path)-1]+1
			temp-=candidates[j-1]
			res=res[0:len(res)-1]
			path=path[:len(path)-1]
			for j==len(candidates){
				if len(path)>0 {
					j=path[len(path)-1]+1
					temp-=candidates[j-1]
					res=res[0:len(res)-1]
					path=path[:len(path)-1]
				}else{
					break
				}
			}
			continue
		}
		if temp+candidates[j]>target {
			if len(path)==0 {
				return ans
			}
			j=path[len(path)-1]+1
			temp-=candidates[j-1]
			res=res[0:len(res)-1]
			path=path[:len(path)-1]
			for j==len(candidates){
				if len(path)>0 {
					j=path[len(path)-1]+1
					temp-=candidates[j-1]
					res=res[0:len(res)-1]
					path=path[:len(path)-1]
				}else{
					break
				}
			}
		}
	}
	return ans
}
```

