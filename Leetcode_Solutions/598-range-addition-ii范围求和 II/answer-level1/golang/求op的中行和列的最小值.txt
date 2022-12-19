### 解题思路
此处撰写解题思路

### 代码

```golang
func maxCount(m int, n int, ops [][]int) int {
	x:=m
	y:=n
	for _,v:=range ops{
		if v[0]<x{
			x=v[0]
		}
		if v[1]<y{
			y=v[1]
		}
	}
	
	return x*y
}
```