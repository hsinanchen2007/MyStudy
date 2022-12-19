### 解题思路
此处撰写解题思路

### 代码

```golang
func countBinarySubstrings(s string) int {
	nums:=make([]int,0)
	//先拿s中的第0个元素出来，nums中第一个元素为1，代表s[0]本身，如果后面的和s[0]相同，则在nums[0]自增1，否则append 新的1
	nums= append(nums, 1)
	for i:=1;i< len(s);i++{
		if s[i]==s[i-1]{
			nums[len(nums)-1]++
		}else{
			nums= append(nums, 1)
		}
	}
	res:=0
	for i:=0;i< len(nums)-1;i++{
		res+=int(math.Min(float64(nums[i]),float64(nums[i+1])))
	}
	return res
}
```