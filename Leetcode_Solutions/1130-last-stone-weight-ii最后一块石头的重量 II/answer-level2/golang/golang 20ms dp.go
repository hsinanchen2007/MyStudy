一个数字要么是被加，要么是被减
核心算法
```
for k := range cur {
			t[k + stones[i]] = struct{}{}
			t[k - stones[i]] = struct{}{}
}
```
整体算法
```
func lastStoneWeightII(stones []int) int {
	cur := map[int]struct{}{
		stones[0]: struct{}{},
		-1 * stones[0]: struct{}{},
	}
	for i := 1; i < len(stones); i++ {
		t := make(map[int]struct{})
		for k := range cur {
			t[k + stones[i]] = struct{}{}
			t[k - stones[i]] = struct{}{}
		}
		cur = t
	}
	ret := 2 << 31
	for k := range cur {
		ret = min(ret, abs(k))
	}
	return ret
}

func abs(x int) int {
	if x < 0 {
		x *= -1
	}
	return x
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
```