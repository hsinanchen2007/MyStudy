### 解题思路
golang 开发者认为 max、min 函数太简单，所以需要开发者自己实现。

这道题最重要的就是 max、min 函数需要自己实现。😁

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) && max(rec1[1], rec2[1]) < min(rec1[3], rec2[3])
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
} 
func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```