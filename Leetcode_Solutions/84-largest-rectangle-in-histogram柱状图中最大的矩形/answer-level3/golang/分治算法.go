

```


// 分治算法
func largestRectangleArea(heights []int) int {
	min := func(l, r int) int { return 0 } // 声明带返回值类型的匿名函数,下面即可重写
	min = func(l, r int) int {
		if r >= len(heights) || l < 0 || l > r{
			return 0
		}
		if l == r {
			return heights[l]
		}

		m := heights[l]
		index := l
		for i := l; i <= r; i++ {
			if heights[i] < m {
				m = heights[i]
				index = i
			}
		}
		cur := m * (r - l + 1) // 当前包含最短木板的面积
		left := min(l, index-1)
		right := min(index+1, r)
		return Max(cur, left, right)
	}
	return min(0, len(heights)-1)
}


func Max(a, b, c int) int {
	tmp := a
	if a < b {
		tmp = b
	}
	if tmp > c {
		return tmp
	}
	return c
}
```