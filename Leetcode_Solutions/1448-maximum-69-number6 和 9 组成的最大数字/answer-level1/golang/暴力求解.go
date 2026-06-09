### 解题思路
暴力

### 代码

```golang
func maximum69Number(num int) int {
	a, b, c, d := num/1000, num/100%10, num/10%10, num%10
	if a == 6 {
		a = 9
	} else if b == 6 {
		b = 9
	} else if c == 6 {
		c = 9
	} else if d == 6 {
		d = 9
	}
	return a*1000 + b*100 + c*10 + d
}
```