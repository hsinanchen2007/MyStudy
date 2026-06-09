### 解题思路
受到了侮辱

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    if rec1[0] <= rec2[0] && rec1[2] <= rec2[0]{
        return false
    }
    if rec2[0] <= rec1[0] && rec2[2] <= rec1[0]{
        return false
    }
    if rec1[1] <= rec2[1] && rec1[3] <= rec2[1]{
        return false
    }
    if rec2[1] <= rec1[1] && rec2[3] <= rec1[1]{
        return false
    }
    return true
}
```