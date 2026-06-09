### 解题思路
首先根据索引r + c的奇偶确定行走的方向，奇数右上，偶数左下。
每次行走方向又有三种边界的情况
	1.top或者down边界都是往右走
	2.left或者right边界都是往下走
	
### 代码

```golang
func findDiagonalOrder(matrix [][]int) []int {
    var rowLen int = len(matrix)
	var result []int
	if rowLen == 0 {
		return result[:]
	}
	var colLen int = len(matrix[0])
	var r int = 0
	var c int = 0
	for i := 0; i < rowLen * colLen; i++{
		result= append(result, matrix[r][c])
		if (r + c) % 2 == 0 {       //和为偶数时 右上方向
			if c == colLen - 1 {		//撞右墙往下走
				r ++
			}else if r == 0 { //撞最上端墙往右走
				c ++
			}else {			//没撞墙斜着走
					c++
					r--
				}
			}else {             //和为奇数时 左下方向
			if r == rowLen - 1 {		//撞下墙往右走
				c ++
			}else if c == 0{	//撞左墙往右走
				r ++
			}else {			//没撞墙斜着走
				c--
				r++
				}
			}
		}
	return result[:]
}
```