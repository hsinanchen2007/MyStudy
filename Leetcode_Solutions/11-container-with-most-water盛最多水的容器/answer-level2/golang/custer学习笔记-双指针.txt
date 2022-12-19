# 第一思路：嵌套循环
执行用时 : 728 ms, 在所有 golang 提交中击败了 9.82% 的用户
内存消耗 : 5.6 MB, 在所有 golang 提交中击败了 65.35% 的用户
```go
func maxArea(height []int) int {
    max := 0 // 记录最大容量
    for i := 0; i < len(height); i++ {
        for j := i + 1; j < len(height); j++ {
            if height[i] < height[j] {
                if max < height[i]*(j-i) {
                    max = height[i] * (j - i)
                }
            } else {
                if max < height[j]*(j-i) {
                    max = height[j] * (j - i)
                }
            }
        }
    }
    return max
}
```

# 双指针
执行用时 : 16 ms , 在所有 golang 提交中击败了 91.98% 的用户
内存消耗 : 5.6 MB , 在所有 golang 提交中击败了 65.35% 的用户
```go
func maxArea(height []int) int {
    i, j := 0, len(height)-1
    ret := 0
    for i < j {
        ret = max(ret, (j-i)*min(height[i], height[j]))
        if height[i] < height[j] {
            i++
        } else {
            j--
        }
    }
    return ret
}

func max(i, j int) int {
    if i < j {
        return j
    }
    return i
}

func min(i, j int) int {
    if i < j {
        return i
    }
    return j
}
```