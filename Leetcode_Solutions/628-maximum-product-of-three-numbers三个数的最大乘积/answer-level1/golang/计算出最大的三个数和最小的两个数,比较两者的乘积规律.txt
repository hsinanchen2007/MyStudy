假设数组按升序排列后, a,b 是数组前面两个数, x,y,z 是数组末尾的三个数, 存在这样的关系: a <= b <= x <= y <= z
当 x, y , z 都大于等于 0 时, x * y * z 就是所求; 只要不满足这个条件, 那么 a * b 必然大于 x * y , 此时 a * b * z 就是所求


```
func maximumProduct(nums []int) int {

	if len(nums) <= 3 {
		r := 1
		for _, v := range nums {
			r *= v
		}
		return r
	}

	a, b := 1000, 1000             // 升序排列后, 数组第一二个下标的值
	x, y, z := -1000, -1000, -1000 // 升序排列后,数组末尾3个下标的值
	for _, v := range nums {
		if v > z {
			x = y
			y = z
			z = v
		} else if v > y {
			x = y
			y = v
		} else if v > x {
			x = v
		}

		if v < a {
			b = a
			a = v
		} else if v < b {
			b = v
		}
	}

	if a*b > y*x {
		return a * b * z

	}

	return z * y * x
}
```