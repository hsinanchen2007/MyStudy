递归加回溯，个人觉得就全排列那种类型的吧，代码如下：
```
func subsets(nums []int) [][]int {
	var res [][]int
	if len(nums)==0 {
		return res
	}
	var temp []int
	getSubsets(&res,nums,&temp,0)
	return res
}
func getSubsets(res *[][]int,nums []int,temp *[]int,n int){
	if n==len(nums) {
		cop:=make([]int,len(*temp))
		copy(cop,*temp)
		*res= append(*res, cop)
		return
	}
	*temp= append(*temp, nums[n])
	getSubsets(res,nums,temp,n+1)
	temp2:=*temp
	temp2=temp2[:len(temp2)-1]
	*temp= temp2
	getSubsets(res,nums,temp,n+1)
}

```
