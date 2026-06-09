核心思想： 分治，先计算最内层的括号，再计算外层的
写的比较乱，直接看注释
```
func braceExpansionII(expression string) []string {
    all, next := [][]string{}, []string{} // all：并集， next：平行数据
	// 判断是否有{,如果没有，说明没有需要合并的，直接split并返回
	idx := strings.Index(expression, "{")
	if idx == -1 {
		return strings.Split(expression, ",")
	}
	start, count := 0, 0
	mid := ""

	// 找到第一个 { 对应的 }, 将里面的数据作为一个exp重新解析。
	for i := 0; i < len(expression); i++ {
		if expression[i] == '{' {
			if count == 0 {
				start = i
			}
			count++
			if mid != "" {
				all = append(all, []string{mid})
				mid = ""
			}
		} else if expression[i] == '}' {
			if count == 1 {
				a := braceExpansionII(expression[start+1:i])
				all = append(all, a) // 需要放到并集，在最后计算
				// 如果下一个数据是 ， 说明前后两组数据是平行的，分别计算
				if i + 1 < len(expression) && expression[i+1] == ',' {
					next = braceExpansionII(expression[i+2:])
					break
				}
			}
			count--
		} else if count == 0 {
			// 记录不在括号里的数据
			if expression[i] == ',' {
				next = braceExpansionII(expression[i+1:])
				break
			}
			mid += string(expression[i])
		}
	}
	// 不要忘记把不在括号里的数据放入并集
	if mid != "" {
		all = append(all, []string{mid})
	}

	// map去重，先求出并集，最后把平行数据也放到map中
	m := make(map[string]struct{})
	m[""] = struct{}{}
	for i := 0; i < len(all); i++ {
		newM := make(map[string]struct{})
		for j := 0; j < len(all[i]); j++ {
			for k := range m {
				newM[k + all[i][j]] = struct{}{}
			}
		}
		m = newM
	}
	for _, n := range next {
		m[n] = struct{}{}
	}
	ret := make([]string, 0, len(m))
	for k := range m {
		ret = append(ret, k)
	}
	// 排序
	sort.Strings(ret)
	return ret
}

```
