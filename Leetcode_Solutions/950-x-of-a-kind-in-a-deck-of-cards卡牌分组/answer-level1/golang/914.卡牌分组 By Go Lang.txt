### 解题思路
1. 循环一遍数组，统计各个整数的个数。
2. 循环处理整数个数的最大公约数GCD，出现<2的情况立刻返回false。
3. 所有整数的最大公约数结果>=2，则true

### 代码

```golang

func hasGroupsSizeX(deck []int) bool {
	M := make(map[int]int)
	for i := 0; i < len(deck); i++ {
		M[deck[i]]++
	}

	if len(M) == 1 {
		for _, v := range M {
			return v >= 2
		}
	}

	var GCD func(x, y int) int
	GCD = func(x, y int) int {
		p1, p2 := x, y
		if p2 > p1 {
			p1, p2 = y, x
		}
		if p1%p2 == 0 {
			return p2
		}
		return GCD(p1%p2, p2)
	}

	var buf []int
	for _, v := range M {
		buf = append(buf, v)
	}

	b1 := buf[0]
	for i := 1; i < len(buf); i++ {
		b2 := buf[i]
		b1 = GCD(b1, b2)
		if b1 < 2 {
			return false
		}
	}
	return true
}

```