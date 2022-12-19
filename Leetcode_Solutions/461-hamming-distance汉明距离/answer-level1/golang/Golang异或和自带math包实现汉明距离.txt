解答一：异或实现
```
func hammingDistance(x int, y int) int {
    res := 0
	n := x ^ y
	for n != 0 {
		res++
		n = n & (n-1)
	}
	return res
}
```

解答二：自带math包
```
func hammingDistance(x int, y int) int {
    return bits.OnesCount(uint(x) ^ uint(y))
}
```

