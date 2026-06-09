- 思路就是去按照题干意思去数
- 如果数字相同，计数+1
- 如果数字不相同，将已经数过的数追加到记录中（这里是c个t连接到str），并且开始数新的数字
- n的结果只需要去数n-1的结果，不需要再申请数组

```go
func countAndSay(n int) string {
	str := "1"
	if n == 1 {
		return str
	}
	for j := 2; j <= n; j++ {
		l, tmp := len(str), str
		t, c := tmp[0], 1
		str = ""

		for i := 1; i < l; i++ {
			if tmp[i] == t {
				c++
			} else {
				str += fmt.Sprintf("%d%d", c, t-'0')
				c = 1
				t = tmp[i]
			}
		}
		str += fmt.Sprintf("%d%d", c, t-'0')
	}
	return str
}
```
