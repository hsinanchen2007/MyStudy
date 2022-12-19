### 解题思路
![1.png](https://pic.leetcode-cn.com/ff1e6429e922cc5289e238f2190e5c394db2ffd103b1bd17ad5fcf870054d560-1.png)
这题和[48. 旋转图像](https://leetcode-cn.com/problems/rotate-image/)是一样的

1、先按中间线，进行上下翻转
2、沿主对角线翻转

如：
  [1,2,3],
  [4,5,6],
  [7,8,9]

步骤1：
  [7,8,9],
  [4,5,6],
  [1,2,3]
步骤二：
  [7,8,9],
  [4,5,6],
  [1,2,3]
### 代码

```golang
func rotate(matrix [][]int)  {
	var i, j int
	n := len(matrix)
	for ;i < n / 2 && i != n - i - 1;i++ {
		// 上下翻转
		for j = 0;j < n;j++ {
			matrix[i][j], matrix[n-i-1][j] = matrix[n-i-1][j], matrix[i][j]
		}
	}
	// 沿主对角线翻转
	for i = 0;i < n;i++ {
		for j = i + 1;j < n;j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}
```