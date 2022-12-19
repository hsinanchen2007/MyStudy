### 解题思路
- 用top，bottom，left，right分别指向上下左右，然后向内循环收缩
- top所在行遍历完后，top+1
- rihgt所在列遍历完后，right-1
- bottom所在行遍历完后，bottom-1
- left所在列遍历完后，left+1

### 代码
```golang
func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return nil
	}

	top := 0
	bottom := len(matrix) - 1
	left := 0
	right := len(matrix[0]) - 1
	k := 0
	res := make([]int, (bottom+1)*(right+1))
	
	for left <= right && top <= bottom {
		//上边一行
		for i := left; i <= right; i++ {
			res[k] = matrix[top][i]
			k++
		}
		top++

		//右边一列
		for i := top; i <= bottom; i++ {
			res[k] = matrix[i][right]
			k++
		}
		right--

		//下边一行
		for i := right; i >= left && top <= bottom; i-- {
			res[k] = matrix[bottom][i]
			k++
		}
		bottom--

		//左边一列
		for i := bottom; i >= top && left <= right; i-- {
			res[k] = matrix[i][left]
			k++
		}
		left++
	}
	return res
}

```

![image.png](https://pic.leetcode-cn.com/f5f949b439b98304d649f58a17053c4a256286f24f969c2a35d5814beefd606e-image.png)
