画图找规律，可以得到分两步：
1、左<--->右互换
2、关于左下/右上的对角线互换，这里只需要遍历矩阵左上角的元素


第二步的规律找的时候费点劲，如下的矩阵，如果要关于左下/右上的对角线互换，需要互换的点为：
```
[
	[ 5,  1,  9, 11],
	[ 2,  4,  8, 10],
	[13,  3,  6,  7],
	[15, 14, 12, 16]
]
```

(0, 2) <---> (1, 3)
(0, 1) <---> (2, 3)
(0, 0) <---> (3, 3)
(1, 1) <---> (2, 2)
(1, 0) <---> (3, 2)
(2, 0) <---> (3, 1)

沿对角线对换，就相当于横、纵坐标沿(0, n) <---> (n, 0)这条线互换，通过找规律得到：
old_i, old_j分别表示原来点的横、纵坐标；
new_i, new_j分别表示兑换后点的横、纵坐标；
	old_i + new_j = n
	old_j + new_i = n

```golang
func rotate(matrix [][]int)  {
	length := len(matrix)

	// 先左<->右互换
	for i := 0; i < length; i++ {
		for j := 0; j < length / 2; j++ {
			matrix[i][j], matrix[i][length - 1 - j] = matrix[i][length - 1 - j], matrix[i][j]
		}
	}

	// 后关于左下/右上的对角线互换
	for i := 0; i < length - 1; i++ {
		for j := 0; j < length - i - 1; j++ {
			matrix[i][j], matrix[length - j - 1][length - i - 1] = matrix[length - j - 1][length - i - 1], matrix[i][j]
		}
	}
}
```