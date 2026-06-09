用一个hash，key是集合中的数字，value是数字出现的次数 。 遍历hash中的key，如果key加上给定的k之后的值在hash中存在则计数加一。当k为0时需要判断hash中的key的value是否小于2，如果小于2则不满足条件。


```

    if k<0 {
		return 0
	}
	m := make(map[int]int)

	for _, v := range nums {
		m[v]++
	}

	count := 0
	for v, num := range m {

		if _, ok := m[v+k]; ok {
			if k == 0 && num < 2 {
				continue
			}
			count++
		}
	}
	return count


```
