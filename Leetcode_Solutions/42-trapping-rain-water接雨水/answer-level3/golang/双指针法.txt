左右两个指针初始时在两端，互相逼近，逼近的过程中算出端点处积水量并累加

```python []
class Solution:
    # 双指针法
    def trap(self, height: List[int]) -> int:
        ans = 0
        if not height: return ans
        # 初始化条件
        n = len(height)
        l, r = 0, n - 1
        maxleft, maxright = height[l], height[r]
        # 在两端引入双指针互相逼近，依次计算紧靠指针的储水量
        while l <= r:
            maxleft = max(maxleft, height[l])
            maxright = max(maxright, height[r])
            if maxleft < maxright:
                ans += maxleft - height[l]
                l += 1
            else:
                ans += maxright - height[r]
                r -= 1
        return ans
```
```go []
func trap(height []int) int {
	ans := 0
	if height == nil || len(height) <= 0 {
		return ans
	}
	n := len(height)
	left, right := 0, n-1
	maxLeft, maxRight := height[left], height[right]
	for ; left <= right; {
		maxLeft = max(maxLeft, height[left])
		maxRight = max(maxRight, height[right])
		if maxLeft < maxRight {
			ans += maxLeft - height[left]
			left++
		} else {
			ans += maxRight - height[right]
			right--
		}
	}
	return ans
}
func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
```
