### 代码

```golang
import (
	"strconv"
)

func translateNum(num int) int {
	count := 0
	var f func(s string)
	f = func(s string) {
		if len(s) == 0 {
            count++
			return
		}
		if len(s) > 1 {
			num, _ := strconv.Atoi(s[0:2])
			if num>=10&&num < 26 {
				f(s[2:len(s)])
			}
		}
		f(s[1:len(s)])
	}
	f(strconv.Itoa(num))
	return count
}
```