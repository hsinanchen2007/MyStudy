直接代码吧，递归+回溯
做个参考

```golang
func subsetsWithDup(nums []int) [][]int {
	var subset []int
	var res [][]int
	sort.Ints(nums)
	used:=make([]int,len(nums))
	getAllSubset(0,nums,used,&subset,&res)
	return res
}

func getAllSubset(i int,nums []int,used []int,subset *[]int,res *[][]int){
	if i==len(nums) {
		cpy:=make([]int,len(*subset))
		copy(cpy,*subset)
		*res=append(*res,cpy)
		return
	}
	getAllSubset(i+1,nums,used,subset,res)
	if i==0||(i>0&&(nums[i]!=nums[i-1]||(nums[i]==nums[i-1]&&used[i-1]!=0))) {
		used[i]=1
		*subset=append(*subset, nums[i])
		getAllSubset(i+1,nums,used,subset,res)
		used[i]=0
		temp2:=*subset
		temp2=temp2[:len(temp2)-1]
		*subset= temp2
	}
}
```