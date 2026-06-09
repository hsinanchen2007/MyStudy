**如图，因为某个节点只能从上层的一个或两个节点移动过来
所以minimumTotal(triangle[i][j]) = triangle[i][j] + min(triangle[i-1][j], triangle[i-1][j-1])**
![image.png](https://pic.leetcode-cn.com/43751d7f17f095db9c8c3d0cdc564d871962e5e956cc0397e2f85120382f30ff-image.png)
<br>
**代码。4 ms, 96.29%。3.1 MB, 88.17%**
```
func minimumTotal(triangle [][]int) int {
	for i := 1; i < len(triangle); i++ {
		for j := 0; j < len(triangle[i]); j++ {
			n := len(triangle[i]) - 1
			if j == 0 {
				triangle[i][0] = triangle[i][0] + triangle[i-1][0]
			} else if j == n {
				triangle[i][n] = triangle[i][n] + triangle[i-1][j-1]
			} else {
				triangle[i][j] = triangle[i][j] + int(math.Min(float64(triangle[i-1][j]), float64(triangle[i-1][j-1])))
			}
		}
	}

	res := math.MaxInt32
	n := len(triangle[len(triangle)-1]) - 1
	for i := 0; i <= n; i++ {
		if triangle[n][i] < res {
			res = triangle[n][i]
		}
	}
	return res
}
```