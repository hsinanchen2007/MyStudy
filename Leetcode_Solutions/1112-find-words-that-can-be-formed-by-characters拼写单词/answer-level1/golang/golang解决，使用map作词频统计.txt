golang解决，使用map作词频统计

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 使用map作词频统计
// 时间复杂度：O(n)  空间复杂度：O(s)  其中，n为所有词的总长度，s为单词组的字符集大小

func countCharacters(words []string, chars string) int {
	cnt := 0

	// 对chars作词频统计，记录于freq_char. freq_chars[k]=3 表示在"chars"中字母"k"出现3次
	freq_chars := make(map[string]int)  
	for i:= 0; i<len(chars); i++ {
		if _,ok := freq_chars[chars[i:i+1]]; ok {
			freq_chars[chars[i:i+1]]++
		}else {
			freq_chars[chars[i:i+1]] = 1
		}
	}

	for _, word := range words {

		if len(word)<len(chars){
			flag := true  // 能否拼出判断位

			// 对word作词频统计
			freq_word := make(map[string]int)
			for i:=0; i<len(word); i++ {
				if _, ok := freq_word[word[i:i+1]]; ok {
					freq_word[word[i:i+1]]++
				}else {
					freq_word[word[i:i+1]] = 1
				}
			}

			// 判断word是否可以用chars中的字母拼出
			for char, freq_in_word := range freq_word {
				if freq_in_chars, ok := freq_chars[char]; 
				!ok || freq_in_chars<freq_in_word {
					flag = false
					break
				}
			}

			if flag {
				cnt += len(word)
			}			
		}
	}

	return cnt
}
```
