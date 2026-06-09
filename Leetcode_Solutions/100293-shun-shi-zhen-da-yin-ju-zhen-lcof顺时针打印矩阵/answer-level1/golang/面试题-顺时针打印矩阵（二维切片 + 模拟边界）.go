### 解题思路
日常学习[@jyd](/u/jyd/)大佬
[大佬的详细图解]](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/mian-shi-ti-29-shun-shi-zhen-da-yin-ju-zhen-she-di/)

### 知识点：二维切片 + 模拟边界

### 代码

```golang
func spiralOrder(matrix [][]int) []int {
   if len(matrix) == 0 {
		return []int{}
	}

	l, r, t, b := 0, len(matrix[0])-1, 0, len(matrix)-1  // 左、右、上、下边界
	var res []int
	for {
		// 从左到右
		for i := l; i < r+1; i++ {
			res = append(res,matrix[t][i])
		}
		t++
		if t > b {
			break
		}

		// 从上到下
		for i := t; i < b+1; i++ {
			res = append(res, matrix[i][r])
		}
		r--
		if l > r {
			break
		}

		// 从右到左
		for i := r; i > l-1; i-- {
			res = append(res, matrix[b][i])
		}
		b--
		if t > b {
			break
		}

		// 从下到上
		for i := b; i > t-1; i-- {
			res = append(res, matrix[i][l])
		}
		l++
		if l > r {
			break
		}
	}
	return res
}

// main
func main() {
	//matrix := [][]int{
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 8, 9},
	//}

	matrix := [][]int{}

	fmt.Println(spiralOrder(matrix))
}
```