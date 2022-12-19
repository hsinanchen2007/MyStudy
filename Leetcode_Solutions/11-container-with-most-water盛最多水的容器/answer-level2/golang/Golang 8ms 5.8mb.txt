### 解题思路
此处撰写解题思路

### 代码

```golang
func maxArea(height []int) int {
    left, right := 0, len(height)-1
    max := 0
    for left < right {
        if (right - left) * min(height[left], height[right]) > max {
            max = (right - left) * min(height[left], height[right])
        }
        if min(height[left], height[right]) == height[left] {
            left += 1
        } else {
            right -= 1
        }
    }
    return max
}

func min(a, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}
```