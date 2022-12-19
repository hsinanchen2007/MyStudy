### 解题思路
不重叠，即A矩形在B矩形上下左右，此时返回false，除此之外都是重叠的情况。

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    a1 := rec1[0]
    b1 := rec1[1]
    a2 := rec1[2]
    b2 := rec1[3]
    x1 := rec2[0]
    y1 := rec2[1]
    x2 := rec2[2]
    y2 := rec2[3]

    if b2 <= y1 || a2 <= x1 || b1 >= y2 || a1 >= x2 {
        return false
    }  
    return true
}
```