```go []
func countCharacters(words []string, chars string) int {
	m := map[rune]int{} // chars map 存放字符与个数映射

	for _, v := range chars {
		m[v]++
	}

	var count int // 返回拼成的词的长度之和

	for _, w := range words {
		c := len(w) // 记录一个词是否被完整拼写
		var i int   // 记录有多少字符参与减, 如果没有符合会补偿回来

		for _, v := range w {
			e, ok := m[v]
			if !ok || e <= 0 {
				break
			}

			c--
			m[v]--
			i++
		}

		if c == 0 {
			count += len(w) // 累加长度

			for _, v := range w { // 补偿整个 w 给 m
				m[v]++
			}
		} else {
			for j := 0; j < i; j++ { // 补偿前 i + 1 个 w 的字符给 m
				m[rune(w[j])]++
			}
		}

	}

	return count
}

```
