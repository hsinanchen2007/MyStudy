### 解题思路
构造一个slice  数据存在就设置成1  然后遍历slice就好了


### 代码

```golang
func firstMissingPositive(nums []int) int {
	l := len(nums)
	s := make([]int,l+2)
	for _,v := range nums{
		if v > 0 && v<=l+1{
			s[v] = 1
		}
	}
	for i:=1;i<=l+1;i++{
		if s[i] == 0{
			return i
		}
	}
	return 0
}
```