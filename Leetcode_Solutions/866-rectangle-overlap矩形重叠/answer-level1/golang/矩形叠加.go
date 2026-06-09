### 解题思路
此处撰写解题思路

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    return !(
        // 左
        rec1[0] >= rec2[2] ||
        // 右
        rec1[2] <= rec2[0] ||
        //上
        rec1[3] <= rec2[1] ||
        // 下
        rec1[1] >= rec2[3])
}
```