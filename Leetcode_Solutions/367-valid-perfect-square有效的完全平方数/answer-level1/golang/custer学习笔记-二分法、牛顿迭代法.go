## 二分法
```go
package main

import "fmt"

func isPerfectSquare(num int) bool {
	l, r := 1, num
	for l <= r {
		m := l + (r-l)/2
		if m*m < num {
			l = m + 1
		} else if m*m > num {
			r = m - 1
		} else {
			return true
		}
	}
	return false
}

func main() {
	n := 5
	fmt.Println(isPerfectSquare(n))
}
```

## 牛顿迭代法

```go
func isPerfectSquare(num int) bool {
	r := num
	for r*r > num {
		r = (r + num/r) / 2
	}
	if r*r == num {
		return true
	}
	return false
}
```