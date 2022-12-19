### 解题思路
golang版本 
先排序
再遍历

### 代码

```golang
type ByLength []string

func (p ByLength) Len() int {
	return len(p)
}
func (p ByLength) Less(i, j int) bool {
	return len(p[i]) > len(p[j])
}
func (p ByLength) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func contain(str, substr string) bool {
	if len(substr) > len(str) {
		return false
	}
	str2 := str[len(str)-len(substr):]
	if substr == str2 {
		return true
	}
	return false
}

func minimumLengthEncoding(words []string) int {

	sort.Sort(ByLength(words)) // 调用按字符串长度排序

	length := len(words)
	res := 0

	hasMap := make([]int, length)

	if length == 1 {
	    return len(words[0]) + 1
	}

	start := words[0]
	substr := words[1]

	for i := 0; i < length && hasMap[i] == 0; i++ {
		start = words[i]
		for j := i + 1; j < length && hasMap[j] == 0; j++ {
			substr = words[j]
			if contain(start, substr) == true {
				hasMap[j] = -1
				hasMap[i] += 1
			}
		}
	}

	for i, v := range hasMap {
		if v >= 0 {
			res += len(words[i])
			res += 1
		}
	}

	return res
}
```