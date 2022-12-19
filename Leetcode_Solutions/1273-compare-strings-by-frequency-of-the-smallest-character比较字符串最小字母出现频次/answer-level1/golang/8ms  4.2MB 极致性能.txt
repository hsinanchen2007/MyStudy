### 完整代码
```
func numSmallerByFrequency(queries []string, words []string) []int {
    // 闭包函数查询字符串中最小字母的出现频次
	f := func(s string) int {
		minCharInfo := struct{
			Char byte
			Count int
		}{}
		for i :=0; i < len(s); i++ {
			if minCharInfo.Count == 0 {
				minCharInfo.Char = s[i]
				minCharInfo.Count = 1
				continue
			}
			if minCharInfo.Char > s[i] {
				minCharInfo.Char = s[i]
				minCharInfo.Count = 1
				continue
			}
			if minCharInfo.Char == s[i]{
				minCharInfo.Count++
				continue
			}
		}
		return minCharInfo.Count
	}
	// 二分查找法 获取已排序数组中大于ltNumber的元素个数
	fFindCount := func(wCounts []int, ltNumber int) int {
		left := 0
		right := len(wCounts) - 1
		middle := 0
		isFind := false // 是否找到ltNumber
		for left <= right {
			 middle = left + ((right - left) >> 1)
			 if wCounts[middle] > ltNumber {
			 	right = middle - 1
			 }else if wCounts[middle] < ltNumber {
			 	left = middle + 1
			 }else {
			 	isFind = true
			 	break
			 }
		}
		minLeft := left
		if isFind { minLeft = middle }
		for minLeft < len(wCounts) {
			if wCounts[minLeft] > ltNumber {
				return len(wCounts[minLeft:])
			}
			minLeft++
		}
		return 0

	}
	
	wCounts := make([]int,len(words), len(words))
    // 获取words中每个词的最小次数
	for index, v := range words {
		wCounts[index] = f(v)
	}
	// wCounts排序
	sortW := sort.IntSlice(wCounts)
	sortW.Sort()
	result := make([]int,len(queries),len(queries))
	for index, v := range queries {
			result[index] = fFindCount(wCounts, f(v))
	}
	return result
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/31166f11f06d013277764c2fbdb5f8824635a18bb154440ccc3d9ac6d6719ea1-image.png)

