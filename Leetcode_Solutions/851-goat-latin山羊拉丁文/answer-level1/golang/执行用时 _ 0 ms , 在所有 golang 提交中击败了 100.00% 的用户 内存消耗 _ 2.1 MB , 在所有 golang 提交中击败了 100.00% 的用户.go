```
func toGoatLatin(S string) string {
  
	sLen := len(S)

	isVowel := false
	firstWord := -1
	str := strings.Builder{}
	wordNum := 1

	for read := 0; read < sLen; read++ {

		//不为空，记录首字母出现的位置,同时检查检查首字母是否元音
		if S[read] != 32 {
			if firstWord == -1 {
				firstWord = read
				isVowel = isVowelsX(S[read])
			}
			continue
		}

		//如果为空,判断首字母是否元音， 如果是，在单词末尾添加ma。如果不是，
		// 移除第一个字符并将它放到末尾，之后再添加"ma"。最后添加索引位a
		if isVowel {
			str.Write([]byte(S[firstWord:read]))
		} else {
			str.Write([]byte(S[firstWord+1:read]))
			str.Write([]byte(S[firstWord:firstWord+1]))
		}
		str.Write([]byte{'m', 'a'})

		j := wordNum
		for j > 0 {
			str.Write([]byte{'a'})
			j--
		}

		wordNum++
		str.Write([]byte{' '})
		firstWord = -1
		isVowel = false
	}

    //这里有个边界，就是处理最后一个单词
	if firstWord != -1 {
		if isVowel {
			str.Write([]byte(S[firstWord:sLen]))
		} else {
			str.Write([]byte(S[firstWord+1:sLen]))
			str.Write([]byte(S[firstWord:firstWord+1]))
		}
		str.Write([]byte{'m', 'a'})
		for wordNum > 0 {
			str.Write([]byte{'a'})
			wordNum--
		}
	}

	return str.String()
}

func isVowelsX(v uint8) bool {
	if v == 65 || v == 97 || v == 69 || v == 101 || v == 73 || v == 105 || v == 79 || v == 111 || v == 85 || v == 117 {
		return true
	}
	return false
}
```
