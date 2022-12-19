====================================================

核心是，考虑能接多少雨水，主要取决于 2 边中小的一边。
所以设置左右指针，不断的变化两边的最高边，交替计算并叠加结果

但是第 32 行有一个问题，有没有可能，右边低于左最高边又高于目前左边，导致 积水面积 = height[right] - height[left] ?
=> 实际上不会，可以按照官方题解的解释：认为如果一端有更高的条形块（例如右端），积水的高度依赖于当前方向的高度（从左到右）。当我们发现另一侧（右侧）的条形块高度不是最高的，我们则开始从相反的方向遍历（从右到左）。
=> 也就是确定了左端为最高端，那么一定会就右端方向（从右到左）来计算积水，而左端实际上一直是最高端，直到出现了右端高于左端的情况，则改变流向（从左到右）来计算。

====================================================

**代码**

```go 
func Trap(height []int) int {
	var leftMax, rightMax, ans int
	left, right := 0, len(height)-1

	for left < right {
		if height[left] < height[right] { // 左边高度少于右边，左边为较小一边，会积水
			if height[left] >= leftMax { // 如果当前高度高于已知左边最高边，则不会积水，且替换为最高边
				leftMax = height[left]
			} else {
				ans += leftMax - height[left] // 如果当前高度低于已知左最高边，又因为上一步，右边已经高于左边，所以形成水坑积水。
			}
			left++
		} else {
			if height[right] >= rightMax {
				rightMax = height[right]
			} else {
				ans += rightMax - height[right]
			}
			right--
		}
	}

	return ans
}
```

**测试代码**
```go
func Test_Trap(t *testing.T) {
	var fibTest = []struct {
		input    []int
		expected int
	}{
		{[]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
	}

	for _, tt := range fibTest {
		actual := Trap(tt.input)
		if actual != tt.expected {
			t.Errorf("Trap(%v) = %v; expected: %v", tt.input, actual, tt.expected)
		}
	}

}
```
