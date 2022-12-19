### 解题思路
1、映射到一位数组上面

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	var x_overlap bool
	var y_overlap bool
	if rec1[2] <= rec2[0] || rec2[2] <= rec1[0] {
		x_overlap =false
	}else{
        x_overlap =true
    }

	if rec1[3] <= rec2[1] || rec2[3] <= rec1[1] {
		y_overlap = false
	}else{
        y_overlap = true
    }
	return x_overlap && y_overlap

}
```