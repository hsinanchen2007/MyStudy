先不看对角线反向，统一从右上往左下方向看对角线，当前对角线上，向下一个元素移动时，[i+1, j-1];
一共有 n + m - 1 条对角线，第一行和最后一列元素，都为对角线起点;

1. 定义result存储最后结果，diagonalLine处理每条对角线元素，n, m分别为行列数
2. 对n+m-1条对角线进行循环遍历，选定第一行与最后一列元素作为对角线起点
3. 使用内循环遍历遍历对角线上的元素[i, j]，注意停止条件 i < n && j > -1
4. 奇数对角线需要反转元素，最后append入result切片中即可

```golang
func findDiagonalOrder(matrix [][]int) []int {
	// 检查空数组
	if matrix == nil || len(matrix) == 0 {
		return []int{}
	}

	// N行， M列
	n, m := len(matrix), len(matrix[0])

	// 存储结果
	var result []int

	// 对角线处理切片
	var diagonalLine []int

	// 切片清空
	//diagonalLine = diagonalLine[:0]

	// 遍历对角线，第一行和最后一列元素都是对角线的起点。则共有n+m-1条对角线
	for i := 0; i < n+m-1; i++ {
		// 清空对角线切片
		diagonalLine = diagonalLine[:0]

		// 对角线起点横坐标
		var a int
		if i < m {
			a = 0
		} else {
			a = i - m + 1
		}

		// 对角线起点纵坐标
		var o int
		if i < m {
			o = i
		} else {
			o = m - 1
		}

		// 找到对角线起点后，开始遍历当前起点为(a, o)的对角线
		for a < n && o > -1 {
			diagonalLine = append(diagonalLine, matrix[a][o])
			// 右上元素往左下移动，(a+1, j-1)
			a++
			o--
		}

		// 如果为奇数对角线，则当前对角线切片元素取反。(因i从0开始，故对2取模为0时需要反转对角线)
		if i%2 == 0 {
			diagonalLine = reverse(diagonalLine)
		}

		result = append(result, diagonalLine...)
	}

	return result
}

// 反转切片
func reverse(s []int) []int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}

	return s
}
```