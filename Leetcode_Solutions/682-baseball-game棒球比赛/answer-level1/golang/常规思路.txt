### 解题思路
此处撰写解题思路

### 代码

```golang
func calPoints(ops []string) int {
	nums:=make([]int,0, len(ops))
	for _,v:=range ops{
		s:=[]rune(v)
		switch s[0]{
		case '+':
			l:= len(nums)-1
			y:=nums[l]+nums[l-1]
			nums= append(nums, y)
		case 'D':
			k:= len(nums)-1
			z:=nums[k]*2
			nums= append(nums, z)
		case 'C':
			nums=nums[:len(nums)-1]
		default:
			x,_:=strconv.Atoi(v)
			nums= append(nums, x)
		}
	}
	res:=0
	for _,v:=range nums{
		res+=v
	}
	return res
}
```