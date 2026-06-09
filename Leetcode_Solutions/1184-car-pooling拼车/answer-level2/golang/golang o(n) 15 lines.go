因为题目限定只有0-1000个车站，所以我们可以通过每个车站的上下车人数计算当前的容量。


遍历trips，当前车站上车即为+， 下车即为-
```
for i := 0; i < len(trips); i++ {
		t := trips[i]
		lt[t[1]] += t[0]
		lt[t[2]] -= t[0]
	}
```

从0开始遍历车站。capacity - lt[i]就是当前车站上完车后还剩余的容量。如果capacity < 0 说明当前容量不够了

完整代码
```
func carPooling(trips [][]int, capacity int) bool {
	lt := [1001]int{} // location
	for i := 0; i < len(trips); i++ {
		t := trips[i]
		lt[t[1]] += t[0]
		lt[t[2]] -= t[0]
	}
	for i := 0; i <= 1000; i++ {
		capacity -= lt[i]
		if capacity < 0 {
			return false
		}
	}
	return true
}

```
