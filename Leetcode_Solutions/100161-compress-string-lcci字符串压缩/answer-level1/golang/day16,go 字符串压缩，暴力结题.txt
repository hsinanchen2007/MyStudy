### 解题思路
此处撰写解题思路

### 代码

```golang
func compressString(S string) string {
	// 1.如果当前字符串等于前一个字符串，则count++，否则count==1
	// 只能依次遍历吗，有没有什么其他方法
	var compress string
	var final string
	for i := 0; i < len(S); i++ {
		var front string
		var cur string
		var count int
		if i > 0 {
			front = S[i-1 : i]
		}
		cur = S[i : i+1]

		if cur == front {
			// 重复需要计数
			var j int
			for j = 0; j < len(compress); j++ {
				if isOk, _ := regexp.MatchString(`^[a-zA-Z]$`, compress[len(compress)-j-1:len(compress)-j]); isOk {
					count, _ = strconv.Atoi(compress[len(compress)-j : len(compress)])
					break
				}
				continue
			}
			count++
			perfix := compress[:len(compress)-j]
			compress = fmt.Sprintf("%s%s", perfix, strconv.Itoa(count))
		} else {
			insertStr := fmt.Sprintf("%s%d", cur, 1)
			compress = fmt.Sprintf("%s%s", compress, insertStr)
		}
	}

	if len(compress) >= len(S) {
		final = S
	} else {
		final = compress
	}

	return final
}

```