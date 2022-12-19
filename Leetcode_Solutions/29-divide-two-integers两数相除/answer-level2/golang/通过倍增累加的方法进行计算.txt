```go
package t0029

import (
	"fmt"
	"log"
)

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func debug(v ...interface{}) {
	log.Println(v...)
}

func toString(i interface{}) string {
	switch i.(type) {
	case int:
		return fmt.Sprintf("%v", i)
	case string:
		return fmt.Sprintf("%v", i)
	case bool:
		return fmt.Sprintf("%v", i)
	default:
		return fmt.Sprintf("%p", i)
	}
}

func divide(dividend int, divisor int) int {
	sym := 1
	if abs(dividend) != dividend {
		sym = -1
	}
	dividend = abs(dividend)
	switch sym {
	case 1:
		if abs(divisor) != divisor {
			sym = -1
		}
	case -1:
		if abs(divisor) != divisor {
			sym = 1
		}
	}
	divisor = abs(divisor)
	count := 0
	for dividend >= divisor {
		c := 0
		dividend, c = find(dividend, divisor)
		count += c
	}
	switch sym {
	case -1:
		count = -count
	}
	if count >= 2147483648 {
		count = 2147483647
	}
	return count
}

func find(s int, d int) (left, count int) {
	sum := d
	count = 1
	left = s
	for sum <= s {
		if sum+sum <= s {
			sum = sum + sum
			count = count + count
			left = s - sum
		} else if sum <= s {
			left = s - sum
			sum = sum + sum
		} else {
			break
		}
	}
	return
}

```