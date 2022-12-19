思路：将所有`n`个`1`的可能组合计算出来


``` go
import (
	"fmt"
)

var watches []string

func readBinaryWatch(num int) []string {
	if num == 0 {
		return []string{"0:00"}
	}
	watches = make([]string, 0)
	watchHelper(num, make([]int, 10), 0)
	return watches
}

func watchHelper(rec int, bits []int, start int) {
	end := 10 - rec
	for start <= end {
		bits[start] = 1
		if rec > 1 {
			watchHelper(rec-1, bits, start+1)
		} else {
			hour := 0
			var i uint32 = 0
			for ; i < 4; i++ {
				hour += bits[i] << (3 - i)
			}
			minute := 0
			for ; i < 10; i++ {
				minute += bits[i] << (9 - i)
			}
			if hour < 12 && minute < 60 {
				watches = append(watches, fmt.Sprintf("%d:%0.2d", hour, minute))
			}
		}
		bits[start] = 0
		start++
	}
}
```