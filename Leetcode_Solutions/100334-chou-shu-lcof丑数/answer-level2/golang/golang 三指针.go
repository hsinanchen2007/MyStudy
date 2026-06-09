### 解题思路

三指针 

### 代码

```golang

func nthUglyNumber(n int) int {
	if n == 1 {
		return 1
	}
	i, j, k := 0, 0, 0
	result := []int{1}
	res := 0
	for n > 1 {
		a := result[i] * 2
		b := result[j] * 3
		c := result[k] * 5
		res = min(min(a, b), c)
		if res == a {
			i++
		}
		if res == b {
			j++
		}
		if res == c {
			k++
		}
		result = append(result, res)
		n--
	}
	return result[len(result)-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```