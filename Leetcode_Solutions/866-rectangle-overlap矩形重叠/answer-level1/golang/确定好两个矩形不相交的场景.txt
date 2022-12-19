### 解题思路

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    //两个矩形不相交的场景，画图更容易理解
    if rec1[2] <= rec2[0] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1] {
        return false 
    } else {
    //其余场景即为两个矩形相交
        return true
    }
}
```