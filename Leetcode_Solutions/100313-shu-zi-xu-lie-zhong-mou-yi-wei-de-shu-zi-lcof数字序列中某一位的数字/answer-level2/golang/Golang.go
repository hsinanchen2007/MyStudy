### 解题思路
![image.png](https://pic.leetcode-cn.com/f4f1e02c3d87db12506b23e78ecd56a9b50b416d363e5f221dab57528a4fb18a-image.png)


### 代码

```golang
import "math"
import "strconv"

func findNthDigit(n int) int {
	if n <= 9 {
		return n
	}
	a := 1
	for {
		x := 9 * int(math.Pow10(a-1)) * a
		if n < x {
			break
		}
		n -= x
		a++
	}
	n--
	number := int(math.Pow10(a-1)) + n/a
	index := n % a
	s := strconv.Itoa(number)
	return int(s[index] - '0')
}
```