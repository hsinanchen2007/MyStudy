### 解题思路
缓存，空间换时间
### 代码

```golang
func trap(height []int) int {
    var res = 0
    l := len(height)
    if l <= 1 {
        return 0
    }
    // 缓存左边最大值和右边最大值数组
    var leftArr = make([]int, l)
    var rightArr = make([]int, l)
    leftArr[0] = height[0]
    for i := 1; i < l; i++ {
        leftArr[i] = max(height[i], leftArr[i - 1])
    }

    rightArr[l - 1] = height[l - 1]
    for i := l - 2; i >= 0; i-- {
        rightArr[i] = max(rightArr[i + 1], height[i])
    }
    // 统计各个点的左右最小最大值的差和
    for i := 0; i < l; i++ {
        res = res + min(leftArr[i], rightArr[i]) - height[i]
    }
    return res
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}
func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}
```