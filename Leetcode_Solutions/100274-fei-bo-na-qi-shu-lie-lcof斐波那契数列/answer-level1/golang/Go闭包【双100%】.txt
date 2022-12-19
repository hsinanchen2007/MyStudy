### 解题思路
此处撰写解题思路

### 代码

```golang
func fib(n int) int {
	var f = fibonacci()
	// 顺序计算，第1项为0，需要调用 f() n+1次
	for i := 0; i < n; i++ {
		f()
	}
	return f()
}

// 使用闭包顺序运算，这里第一项为0
func fibonacci() func() int {
	const mod = 1e9 + 7
	f, g := 1, 0
	return func() int {
		f, g = g, (f+g)%mod
		return f
	}
}
```