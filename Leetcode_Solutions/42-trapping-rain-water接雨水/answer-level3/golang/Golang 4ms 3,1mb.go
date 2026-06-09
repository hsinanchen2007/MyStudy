### 解题思路
此处撰写解题思路

### 代码

```golang
func trap(height []int) int {
    if len(height) <= 2 {
        return 0
    }
    maxLeft, maxRight := make([]int, len(height)), make([]int, len(height))
    maxLeft[0], maxRight[len(height)-1] = height[0], height[len(height)-1]
    res := 0
    for i := 1; i < len(height); i++ {
        maxLeft[i] = max(maxLeft[i-1], height[i])
        maxRight[len(height)-i-1] = max(maxRight[len(height)-i], height[len(height)-i-1])
    }
    for i := 0; i < len(height); i++ {
        if min(maxLeft[i], maxRight[i]) > height[i] {
            res += min(maxLeft[i], maxRight[i]) - height[i]
        }
    }
    return res
}

func max(a, b int) int {
    if a > b {return a}
    return b
}

func min(a, b int) int {
    if a > b {return b}
    return a
}
```