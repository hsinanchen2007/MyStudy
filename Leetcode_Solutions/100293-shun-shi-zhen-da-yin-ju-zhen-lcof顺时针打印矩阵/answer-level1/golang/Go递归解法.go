# 解题思路
看了一下好像没有用递归做的，分享下自己的代码。
1.由题意很容易可以看出可以该题可以划分出子问题：
设f(rows, cols, start)为以cmatrix[start][start]开始顺时针打印rows行cols列,
则f(rows, cols, start) = 先打印最外圈 + f(rows-2, cols-2, start+1)，
即每次行和列-2，起始横纵坐标+1，结束条件为行数和列数二者其一为0，也就是没有元素了。
2.然后对于打印最外圈，依次→、↓、←、↑即可，
控制好边界条件，唯一需要注意的是**当只有一行或一列时不再需要←、↑返回**，
因为→和↓已经将唯一路径覆盖，这时直接跳出递归
# 代码
```
func spiralOrder(matrix [][]int) []int {
	var res []int
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return res
	}
	rows, cols := len(matrix), len(matrix[0])
	start := 0
	var print func(x, y int)
	print = func(x, y int) {
		res = append(res, matrix[x][y])
		if x == start && y < start+cols-1 {
			print(x, y+1)
		}
		if x < start+rows-1 && y == start+cols-1 {
			print(x+1, y)
		}
		// 这里判断是否只有一行或一列，直接跳出
		if rows == 1 || cols == 1 {
			return
		}
		if x == start+rows-1 && y > start {
			print(x, y-1)
		}
		if x > start+1 && y == start {
			print(x-1, y)
		}
	}
	// 行或列<=0结束
	for rows > 0 && cols > 0 {
		print(start, start) // 传入参数为每圈的起始坐标
		rows, cols, start = rows-2, cols-2, start+1 //每圈结束将行列-2，起始坐标+1
	}
	return res
}

```
