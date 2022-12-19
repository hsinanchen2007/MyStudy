	maps := make(map[int]int)
	res = make([]int, 0)

	for key, val := range nums {
		ant := target - val
		_, ok := maps[ant]
		if ok {
			res = append(res, key)
			res = append(res, maps[ant])
			break
		}
		maps[val] = key
	}
	return