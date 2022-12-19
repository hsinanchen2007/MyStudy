### 解题思路
一开始用的正向思路，检查点是否包含在其中，发现情况种类很多

开始用反向思路，检查第二个矩形的两个点都不在或者在第一个矩形边上的情况

### 代码

```golang
// 检查 rec2 的两个点，若其中有一个点在rec1内，则重叠
// 正向情况太多，用反向思维，检查不在其中的情况
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    if len(rec1) != 4 || len(rec2) != 4 {
        return false
    }

    rec1X1 := rec1[0]
    rec1Y1 := rec1[1]
    rec1X2 := rec1[2]
    rec1Y2 := rec1[3]

    rec2X1 := rec2[0]
    rec2Y1 := rec2[1]
    rec2X2 := rec2[2]
    rec2Y2 := rec2[3]

    if (rec1X1 >= rec2X2 || rec1Y1  >= rec2Y2 || rec1X2 <= rec2X1 || rec1Y2 <= rec2Y1) {
        return false
    }

    return true
}
```