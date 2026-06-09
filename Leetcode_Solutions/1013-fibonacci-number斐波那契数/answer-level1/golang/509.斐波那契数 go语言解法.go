### 解题思路

简单题，也不想巧妙的解法了，简单粗暴的解法，直接上代码。

### 代码

```golang
func fib(N int) int {
	if N == 0 || N == 1 {
		return N
	}else {
		return F(N - 1) + F(N - 2)
	}
}
func F(N int) int {
	res := 0
	if N == 0 || N == 1 {
		res = N
	} else {
		res = fib(N-1) + fib(N-2)
	}
	return res
}
```