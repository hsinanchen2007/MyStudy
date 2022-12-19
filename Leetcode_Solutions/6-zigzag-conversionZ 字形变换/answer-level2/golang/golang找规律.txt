执行0ms, 内存4.1MB  > O <
```
func convert(s string, numRows int) string {
	var result []uint8
	groupLenth := 2 * numRows -2
	lenth := len(s)
	if groupLenth == 0 {
		return s
	}
	for i :=0; i < numRows; i++ {
		for j := i; j < lenth; j += groupLenth {
			result = append(result, s[j])
			if i != 0 && i != (numRows - 1){
				index := 2 * (numRows - i - 1) + j
				if index < lenth {
					result = append(result, s[index])
				}
			}
		}
	}
	return string(result)
}
```
1. 其实画个索引排列就好，一个V字形就是一组，列固定添加进来，斜着的只有中间的有
2. 第一行和最后一行直接检查索引后添加
3. 中间行固定添加第一个值，第二个索引固定为  每组起始点 + 2 * (行数 - 当前行数 - 1)