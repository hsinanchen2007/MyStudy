### 解题思路
此处撰写解题思路

### 代码

```golang
func maxArea(height []int) int {
    // 计算以ai结尾最大的一个量
    res := 0
    for i := 1; i < len(height); i++ {
        for j := 0; j < i; j++ {
            tmp := min(height[i], height[j])
            dis := i - j
            if res < tmp * dis {
                res = tmp * dis
            }
        }
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