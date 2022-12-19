### 解题思路
算法：遍历s，map缓存字符和次数，遍历map，不断对keys升序/降序排序，并append进结果，直到达到s的长度。

### 代码

```golang
func sortString(s string) string {
	var res []string
	occMap := make(map[string]int)
	for _, b := range s{
		occMap[string(b)]++
	}
	selectMax := false
	for len(res) < len(s) {
		// first round, select min num
		// 每次都会重新初始化
		var keys []string
		for k, v := range occMap{
			if v == 0 {
				delete(occMap, k)
				continue
			}
			keys = append(keys, k)
			occMap[k]--
		}

		if selectMax {
			sort.Sort(sort.Reverse(sort.StringSlice(keys)))
			selectMax = !selectMax
		}else {
			sort.Strings(keys)
			selectMax = !selectMax
		}
		res = append(res, keys...)
	}
	return strings.Join(res, "")
}
```