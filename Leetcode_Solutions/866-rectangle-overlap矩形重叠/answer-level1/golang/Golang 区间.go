### 解题思路
此处撰写解题思路

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    return hasInterval(rec1[0],rec1[2],rec2[0],rec2[2]) && hasInterval(rec1[1],rec1[3],rec2[1],rec2[3])

}

func hasInterval(x1,x2,x3,x4 int) bool {
    var (
        x = 0
        y = 0
    )
    if x1 < x3 {
        x = x2
        y = x3
    }else {
        x = x4
        y = x1
    }
    if y < x {
        return true
    }
    return false
}
```