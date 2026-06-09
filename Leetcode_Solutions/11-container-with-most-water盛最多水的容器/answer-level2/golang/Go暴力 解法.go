### 解题思路
Go暴力 解法

### 代码

```golang
func maxArea(height []int) int {
    	max_contain := 0
	aera := 0
	for i := 0; i < len(height)-1; i++ {
		for j := i + 1; j < len(height); j++ {
			aera = (j - i) * min(height[j], height[i])
			max_contain = max(aera, max_contain)
		}
	}
	return max_contain
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```