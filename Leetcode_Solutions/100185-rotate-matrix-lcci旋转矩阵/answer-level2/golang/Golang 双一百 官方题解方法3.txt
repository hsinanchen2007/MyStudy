### 解题思路
官方题解 方法3：用翻转代替旋转
和其他题解基本大同小异。

### 代码

```golang
func rotate(matrix [][]int)  {

    // 获取N
	N := len(matrix)

	// 先水平翻转
	for y := 0; y < (N / 2); y++ {
		matrix[y], matrix[N-1-y] = matrix[N-1-y], matrix[y]
	}

	// 再按主对角线进行元素翻转
	for y := 0; y < N; y++ {
		/*
            这里需要注意，如果用 x<N 这个条件，会导致对角线元素翻转两次，最终恢复原状，所以要 x<y
            使得翻转的过程只进行一次，即
            y=0时，不进行翻转
            y=1时，只进行(1,0)和(0,1)元素翻转
            y=2时，(2,0)和(0,2)，(2,1)和(1,2)翻转
		*/
		for x := 0; x < y; x++ {
			matrix[y][x], matrix[x][y] = matrix[x][y], matrix[y][x]
		}
	}
}
```

### 运行结果
![image.png](https://pic.leetcode-cn.com/f6276f5d25e2275bbef626672b547ced4ed9c19edfd64a30f6cb7b8ef485b5bb-image.png)
