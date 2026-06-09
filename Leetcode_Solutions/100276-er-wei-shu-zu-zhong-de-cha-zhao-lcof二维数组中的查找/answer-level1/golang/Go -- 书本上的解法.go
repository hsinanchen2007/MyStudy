### 解题思路
按照书本的C#代码改写的Go代码
但是我的代码比书本的简洁
从右向左, 从上到下进行判断
注意坑点:
leetcode有一个用例是空的二维数组, 我找了很多的办法, 最后用cap判断对象数组的容量是否为0来实现判断
其他没有了, 思路是书本上的.
### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool {
	// 从右上角开始, 从右向左, 从上到下哦

	if cap(matrix) == 0 {
		return false
	}

	row := 0
	column := len(matrix[0]) - 1
	for column >= 0 && row <= len(matrix) - 1{  // 列大于0
		// 行小于行高减一
		if matrix[row][column] == target {
			return true
		} else if matrix[row][column] > target {
			column -= 1
		} else {
			row += 1
		}
		// 如果在这个循环没有得到结果，就说明没有目标值
		// 退出循环，返回false
		//break
	}
	return false
}
```