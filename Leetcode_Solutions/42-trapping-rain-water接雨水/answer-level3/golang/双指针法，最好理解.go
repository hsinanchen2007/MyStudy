### 解题思路
此处撰写解题思路

### 代码

```golang
func trap(height []int) int {
    l := len(height)
    // 双指针法，最优解
    left := 0
    right := l - 1

    // 左，右最大值记录
    leftMax := 0
    rightMax := 0
    // 返回值
    res := 0
    for left < right {
        if height[left] < height[right] {
            if height[left] > leftMax {
                leftMax = height[left]
            } else {
                res = res + leftMax - height[left]
            }
            left++
        } else {
            if height[right] > rightMax {
                rightMax = height[right]
            } else {
                res = res + rightMax - height[right]
            }
            right--
        }
    }
    return res
}
```