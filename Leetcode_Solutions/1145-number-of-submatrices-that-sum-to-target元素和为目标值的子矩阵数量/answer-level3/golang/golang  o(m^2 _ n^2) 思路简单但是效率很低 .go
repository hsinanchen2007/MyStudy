### 解题思路：
首先我们计算以 `(0，0)` 和任意点作为矩阵端点的和。通过遍历横坐标和纵坐标计算。（添加一行一列方便结算）

每一个点的和应该是：对应上一行当前列的和 + 当前行的和，即
`sum[i+1][j+1] = t + sum[i][j+1] // t`为每一行的累加和。

以 `[[ 1,2,3],[4,5,6],[7,8,9]]`为例，计算后的结果为：

![image.png](https://pic.leetcode-cn.com/8a576e9e0eebef5ccdd4b75ac18e1265d0c2d3ef3abbf5e87cb6a32279da0cfd-image.png){:width=400}
{:align=center}


下一步就是暴力求解任意两个点组成的矩阵的和 假设我们要求`[(2，1)(2，2)]`, 也就是下图红色部分。

![image.png](https://pic.leetcode-cn.com/5ece6476da3e9b1992b929f26fb1c9df53539c89d658cd6c7d6a9a98e1ad66c2-image.png){:width=400}
{:align=center}

`(2，2)`这个点的值就是 `[(0，0) ( 2，2)]`这个矩阵的和。我们的目的是要把其他颜色都减去，因为我们知道所有点和`(0，0)`组成矩形的和

首先我们减去`[(0，0)(1，2)]`这个矩阵，即黄色部分+蓝色部分。

然后我们减去`[(0，0)(2，0)]`这个矩阵，即黄色部分+绿色部分。

这里我们发现黄色部分被减了两次，所以我们需要再加上黄色部分。

`45 - 12 - 21 + 5 = 8 + 9 = 17`

成功求得红色部分的值。核心代码为：
```
v := sum[i][j] - sum[x-1][j] - sum[i][y-1] + sum[x-1][y-1]
```

### 完整代码：
```go [-GO]

func numSubmatrixSumTarget(matrix [][]int, target int) int {
	m, n := len(matrix), len(matrix[0])
	sum := make([][]int, m + 1)
	for i := 0; i < len(sum); i++ {
		sum[i] = make([]int, n + 1)
	}
	for i := 0; i < len(matrix); i++ {
		t := 0
		for j := 0; j < len(matrix[i]); j++ {
			t += matrix[i][j]
			sum[i+1][j+1] = t + sum[i][j+1]
		}
	}
	count := 0
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			for x := 1; x <= i; x++ {
				for y := 1; y <= j; y++ {
					v := sum[i][j] - sum[x-1][j] - sum[i][y-1] + sum[x-1][y-1]
					if v == target {
						count++
					}
				}
			}
		}
	}
	return count
}
```
