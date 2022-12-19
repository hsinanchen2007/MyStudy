### 解题思路
分别找出每个点左边和右边的最大值，然后用最小的减去当前值

### 代码

```golang
func trap(height []int) int {
    // 暴力法
    var res = 0
    l := len(height)
    if l <= 1 {
        return 0
    }
    for i := 1; i < l; i++ {
        // maxLeft, maxRight 分别记录左边和又变最大
        maxLeft := 0
        maxRight := 0
        for j := i; j >=0; j-- {
            if maxLeft < height[j] {
                maxLeft = height[j]
            }
        } 
        for j := i; j < l; j++ {
            if maxRight < height[j] {
                maxRight = height[j]
            }
        }
        tmp := min(maxLeft, maxRight)
        res = res + tmp - height[i]
    }
    return res
}

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

```