
思路：先生成三角边，然后再计算里面的数值
```
func generate(numRows int) [][]int {
	out := make([][]int, numRows)
	// 生成三角边
	for i := 0; i < numRows; i++ {
		tmp := make([]int, i+1)
		// 将对角线和左侧置1
		tmp[0],tmp[i]=1,1
		out[i]=tmp


	}
	// 计算杨辉三角内的其他数
	for i := 2; i < numRows; i++ {
		// i为行数
		for j := 1; j < i; j++ {
			out[i][j] = out[i-1][j] + out[i-1][j-1]
		}
	}
	return out
}

```

![image.png](https://pic.leetcode-cn.com/dc366400cfc522ca97a13e6fb230ee96741cfebf5321d7cf0b3f9fc640c64812-image.png)

