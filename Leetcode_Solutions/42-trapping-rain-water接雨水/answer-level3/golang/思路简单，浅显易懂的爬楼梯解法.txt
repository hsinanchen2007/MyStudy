这个题目有个最好理解的思路，就是先找到最高点，然后将整个 List 分成两部分去解决。

找到最高点后，采取从两边「爬楼梯」的方式来统计存水的多少，正常的楼梯是不会存水的，因为楼梯都是节节高的。

从左右两边开始爬，爬楼的过程中维护当前爬楼的不存水的楼梯高度。低于这个高度的楼肯定会存水，这时很容易就能计算出存水量。


```
func Trap(height []int) int {
	if len(height) <= 2 {
		return 0
	}
	// 找到最大值
 	maxIndex := 0
	for i := 0; i < len(height); i++ {
		if height[maxIndex] < height[i] {
			maxIndex = i
		}
	}
	var leftWater int
	var rightWater int
	leftMax := height[0]
	// 从左往右爬楼，爬到最高
	for j := 0; j < maxIndex; j++ {
		if height[j] < leftMax {
			leftWater += leftMax - height[j]
		} else {
			leftMax = height[j]
		}
	}
	// 从右往左爬楼，爬到最高
	rightMax := height[len(height) - 1]
	for k := len(height) - 1; k > maxIndex; k-- {
		if height[k] < rightMax {
			rightWater += rightMax - height[k]
		} else {
			rightMax = height[k]
		}
	}
	return leftWater + rightWater
}
```
