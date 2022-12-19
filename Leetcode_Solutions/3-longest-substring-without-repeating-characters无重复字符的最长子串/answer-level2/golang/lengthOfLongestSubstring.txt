```
import "math"

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	res := 0
	start := 0
	dic := make(map[rune]int)
	for i, v := range s {
		if _, ok := dic[v]; ok {
			res = int(math.Max(float64(res), float64(i-start)))
			start = int(math.Max(float64(start), float64(dic[v]+1)))
		}
		dic[v] = i
	}
	return int(math.Max(float64(len(s)-start), float64(res)))

}
```
