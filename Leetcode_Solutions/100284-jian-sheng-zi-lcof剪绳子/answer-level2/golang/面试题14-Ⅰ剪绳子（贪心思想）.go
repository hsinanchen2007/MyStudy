学习[@jyd](/u/jyd/)大佬的python3解法的Golang解法

```
package main

import (
	"fmt"
	"math"
)

func cuttingRope(n int) int {
	if n <= 3 {
		return n-1
	}
	a, b := n / 3, n % 3
	if b == 0 {
		return int(math.Pow(float64(3), float64(a)))
	}
	if b == 1 {
		return int(math.Pow(float64(3), float64(a-1)) * 4)
	}
	return int(math.Pow(float64(3), float64(a)) * 2)
}

func main() {
	n := 10
	fmt.Println(cuttingRope(n))
}
```

