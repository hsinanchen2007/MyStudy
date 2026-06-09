```

	orderMap := map[string]int{}

	// 字典序
	for i, v := range order {
		orderMap[string(v)] = i
	}

	l1, l2 := 1, 1


	var k1, k2 string
	count := 0
	// 1. 比较相邻单词顺序,
	// 2. 字符相等进行下一个字符比较，字符遍历往后，如后面的字符较短，则返回false
	b := false

	for j := 0; j < len(words) - 1; j++ {
		count = 0
		l1 = len(words[j])
		l2 = len(words[j+1])

		for l1 > count && l2 > count {
			k1 = string(words[j][count:count+1])
			k2 = string(words[j+1][count:count+1])
			count ++
			if k1 == k2 {
				continue
			}
			if orderMap[k1] < orderMap[k2] {
				b = true
				break
			} else {
				return false
			}
		}

		if !b && l1 > l2 {
			return false
		}
	}


	return true
```
