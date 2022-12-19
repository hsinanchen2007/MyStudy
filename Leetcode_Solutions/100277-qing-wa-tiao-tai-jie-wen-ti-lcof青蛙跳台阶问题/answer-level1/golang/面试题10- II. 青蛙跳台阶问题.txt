### 解题思路
此处撰写解题思路

### 代码

```golang
func numWays(n int) int {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return 1
	}
	var a int64 = 1
	var b int64 = 1
	for i := 2; i <= n; i++ {
		a, b = b, (a+b)%int64(1000000007)
	}
	return int(b)
}
```