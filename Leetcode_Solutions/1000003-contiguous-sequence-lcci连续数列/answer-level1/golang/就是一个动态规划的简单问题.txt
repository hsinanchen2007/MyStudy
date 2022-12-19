### 解题思路
利用动态规划解题

### 代码

```golang
func maxSubArray(nums []int) (n int) {
	if len(nums) == 0{
		return
	}
	sum := math.MinInt32
    	n = sum
	for _,v := range nums{
		sum = max(v,sum+v)
		n = max(n,sum)
	}
	return n
}
func max(a,b int) int {
	if a<b{
		a=b
	}
	return a
}
```