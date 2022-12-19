

![image.png](https://pic.leetcode-cn.com/5ad8c1fb14ca1e2178d045f0e9018435bfc1e005225f408f58fdbacfa6bddde0-image.png)

```
func minMutation(start string, end string, bank []string) int {
	// 边界条件
	if len(start) == 0 || len(end) == 0 {
		return -1
	}
	flag := false
	for _, s := range bank {
		if end == s {
			flag = true
		}
	}
	if !flag {
		return -1
	}
	if start == end {
		return 0
	}

	queue := []string{start}
	count := 0
	bankMap := make(map[string]bool)
	for len(queue) > 0 {
		count++
		newQueue := make([]string, 0)
		for _, ss := range queue {
			for _, bs := range bank {
				if !bankMap[bs] {
					diff := 0
					for i := 0; i < len(bs); i++ {
						if ss[i] != bs[i] {
							diff++
						}
					}
					if diff == 1 {
						bankMap[bs] = true
						if bs == end {
							return count
						}
						newQueue = append(newQueue, bs)
					}
				}
			}
		}
		queue = newQueue
	}
	return -1
}
```
