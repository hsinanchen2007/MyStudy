```
func findRestaurant(list1 []string, list2 []string) []string {
    m := make(map[string]int)
	for i, l := range list1 {
		m[l] += i
	}

	result := []string{}
	min := 1998

	for i, l := range list2 {
		if _, ok := m[l]; ok {
			if m[l]+i == min {
				result = append(result, list1[m[l]])
			}
			if m[l]+i < min {
				result = []string{list1[m[l]]}
				min = m[l] + i
			}
		}
	}

	return result
}
```