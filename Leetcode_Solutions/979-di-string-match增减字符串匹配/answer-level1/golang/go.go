### 解题思路
此处撰写解题思路

### 代码

```golang
func diStringMatch(S string) []int {
	N:= len(S)
	nums:=make([]int,0)
	for i:=0;i<=N;i++{
		nums= append(nums, i)
	}
	str:=[]rune(S)
	res:=make([]int,0)
	for i:=0;i< len(str);i++{
		if str[i]=='I'{
			res= append(res, nums[0])
			nums=nums[1:]
		}else{
			res= append(res, nums[len(nums)-1])
			nums=nums[:len(nums)-1]
		}
	}
	res= append(res, nums[0])
	return res
}
```