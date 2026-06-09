### 解题思路

可以观察到，相邻数都不相同的数有一个规律：
0		0
1		1
10		2
101		5
1010	10
10101	21
101010	42
即每次×2或者×2+1是下一次的值，所以根据这个规律解题便很容易了。执行用时和内存消耗都为100%。
### 代码

```golang
func hasAlternatingBits(n int) bool {
	if n == 0 || n == 1 {
		return true
	}
	tmp := 1
	i := 1
	for tmp < n {
		if i % 2 == 0 {
			tmp = tmp * 2 + 1
		}else {
			tmp *= 2
		}
		if tmp == n {
			return true
		}
		i++
	}
	return false
}
```