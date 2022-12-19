````
func countAndSay(n int) string {
	// 递归出口
	if n == 1 {
		return "1"
	}
	// 获得上一项的值, 连续计数器, 用于拼接的字符串
	prev := countAndSay(n - 1)
	count, lastIndex := 1, len(prev) - 1
	var result strings.Builder

	for i := range prev[ :lastIndex] {
		// 当前值和下一个值不相等, 追加字符: count个prev[i], 重置计数器
		if prev[i] != prev[i + 1] {
			result.WriteString(strconv.Itoa(count))
			result.WriteByte(prev[i])
			count = 1
		} else {
			count++
		}
	}
	// 补充上最后的值
	result.WriteString(strconv.Itoa(count))
	result.WriteByte(prev[lastIndex])
	return result.String()
}
````