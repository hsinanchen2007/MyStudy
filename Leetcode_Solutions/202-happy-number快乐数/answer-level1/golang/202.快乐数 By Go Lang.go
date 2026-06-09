### 解题思路
循序渐进，保存中间结果，如果出现循环并且不是1，则不是快乐数。

### 代码

```golang

func square(n int) int {
	var buf []int
	for n >= 10 {
		buf = append(buf, n%10)
		n /= 10
	}
	buf = append(buf, n%10)
	s := 0
	for _, v := range buf {
		s += v * v
	}
	return s
}
func isHappy(n int) bool {
	h := make(map[int]int)

	c := n
	var ok bool
	_, ok = h[c]
	for !ok {
		h[c]++
		c = square(c)
		_, ok = h[c]
	}

	if c == 1 {
		return true
	}
	return false
}

```