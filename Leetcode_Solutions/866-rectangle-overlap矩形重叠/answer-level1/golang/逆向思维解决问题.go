### 解题思路
考虑到矩形的边界会重合，使用排除的思路解决不相交的情况

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
  if(rec1[0] >= rec2[2] || rec1[2]<=rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]){
    return false
  }else{
    return true
  }
}
```