### 解题思路
此处撰写解题思路

### 代码

```golang
func fib(n int) int {
	if n==0 || n==1 {
		return n
	}

	s := make([]int,n+1)
	s[0] = 0
	s[1] = 1
	for i:=2;i<=n;i++ {
		s[i] = (s[i-1] + s[i-2]) % 1000000007
	}

	return s[n]
}
```