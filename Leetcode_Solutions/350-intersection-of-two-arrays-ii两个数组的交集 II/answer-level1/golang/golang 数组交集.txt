1. 遍历nums1数组，用map保存其中数据的信息，key, count
2. 遍历nums2数组，查看value对应的map的信息，如果map存在，并且key对应的count大于０，　则将这个key添加到返回的数组中，并且使得key　对应的value-1

func intersect(nums1 []int, nums2 []int) []int {
    mapLenght := int(math.Max(float64(len(nums1)), float64(len(nums2))))
	resultSlice := []int{}

	m := make(map[int]int, mapLenght)
	for _, value := range nums1 {
		if _, ok := m[value]; !ok {
			m[value] = 1
		} else {
			m[value]++
		}
	}

	for _, value := range nums2 {
		if _, ok := m[value]; ok {
			if m[value] > 0 {
				resultSlice = append(resultSlice, value)
			}
			m[value]--
		}
	}

	return resultSlice
}