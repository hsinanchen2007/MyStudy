### 代码

```golang
func maxProduct(nums []int) int {
	var (
		result = math.MinInt32
		iMax   = 1
		iMin   = 1
	)
	for i:=0;i<len(nums);i++{
		if nums[i]<0{
			iMax, iMin = iMin, iMax
		}
		iMax = max(iMax*nums[i],nums[i])
		iMin = min(iMin*nums[i],nums[i])
		result = max(result, iMax)
	}
	return result
}

func max(a int, b int) int {
	if a > b{
		return a
	}
	return b
}

func min(a int, b int) int {
	if a > b{
		return b
	}
	return a
}
```