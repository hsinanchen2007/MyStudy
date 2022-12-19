### 解题思路
题意有点难理解，这个代码，有点慢，240ms，但是内存挺省的，4.3M的内存消耗。
题目坑的地方在于，要找到的时最小字母的频次，所以要先找出最小字母，再对这个字母计数。

### 代码

```golang
func numSmallerByFrequency(queries []string, words []string) []int {
	var result []int

	var qc int = 0
	// 这个计数字母出现频次
	for qi, qv := range queries{
		result = append(result, 0)
		qc = countMaxCountInAWord(qv)	// 计数最大字母次数
		for _, wv := range words{
			if qc < countMaxCountInAWord(wv) {
				result[qi] = result[qi] + 1
			}
		}
	}
	return result
}

func countMaxCountInAWord(word string) int {
	var minAlpbat int32 = 200
	for _, v := range word{
		// 先找出最小的字母
		if minAlpbat > v {
			minAlpbat = v
		}
	}
	times := 0
	for _, v := range word{
		if minAlpbat == v {
			times += 1
			// 统计次数
		}
	}
	return times
}

```