### 解题思路
此处撰写解题思路

### 代码

```golang
func hasAlternatingBits(n int) bool {
	nums:=make([]int,0)
	for n>0{
		x:=n&1
		nums= append(nums, x)
		n=n>>1
	}
	for i:=0;i< len(nums)-1;i++{
		if nums[i]==nums[i+1]{
			return false
		}
	}
	return true
}
```