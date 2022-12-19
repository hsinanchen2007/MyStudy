### 解题思路
此处撰写解题思路
1 2 3 4 5 6 7
选不选择导致的影响
选择1 导致结果只能从3开始选
不选择1 结果可以从2开始选(包含从3开始选 后续的影响一样 所以我们只需要考虑当前选择的这个和不选择哪个大)
可先讲remind注释掉 此处就是为了节约时间  你会发现从3开始的算了2遍（选择不选择都算了一遍）
### 代码

```golang
var l=0
//去冗余
var remind []int
func rob(nums []int) int {
	l=len(nums)
	remind=make([]int,l)
	for i:=range remind{
		remind[i]=-1
	}
	return rob1(0,nums)
}
func rob1(idx int,nums []int) int {
	if idx>=l{
		return 0
	}
	if remind[idx]>=0{
		return remind[idx]
	}
	//选择了当前这个数字(结果就是钱数+nums[idx]) 导致idx+1不能选取
	xz:=rob1(idx+2,nums)+nums[idx]
	//不选择当前这个数字  可以选取idx+1
	bxz:=rob1(idx+1,nums)
	remind[idx]=max(xz,bxz)
	return remind[idx]
}
func max(a,b int)int{
	if a>b{
		return a
	}else{
		return b
	}
}
```