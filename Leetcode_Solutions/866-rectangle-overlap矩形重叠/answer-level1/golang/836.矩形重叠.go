### 解题思路

判断位置即可，排除rec1在rec2的上下左右四个方向外，其余都重叠。

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	return !(rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3])
}
```