![image.png](https://pic.leetcode-cn.com/b157e2edda61128d39f1d116a5e754e2a09838ad2a1823471186f126501c298f-image.png)

1. 旋转次数由矩阵宽高短的一边决定
2. 首先确定每次旋转起始点坐标
3. 按照本次旋转起始点依次遍历上下左右四条边


```
func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func spiralOrder(matrix [][]int) (res []int) {
	height := len(matrix)
	if height == 0 {
		return
	}
	width := len(matrix[0])
	if width == 0 {
		return
	}
	res = make([]int, 0, height*width)
	m := (width + 1) / 2
	n := (height + 1) / 2
	for i := 0; i < min(m, n); i++ {
		for j := i; j < width-i; j++ { // 上
			res = append(res, matrix[i][j])
		}
		for j := i + 1; j < height-i; j++ { // 右
			res = append(res, matrix[j][width-1-i])
		}
		for j := width - i - 1 - 1; j >= i && height-1-i > i; j-- { // 下
			res = append(res, matrix[height-1-i][j])
		}
		for j := height - i - 1 - 1; j >= i+1 && i < width-1-i; j-- { // 左
			res = append(res, matrix[j][i])
		}
	}
	return
}
```
