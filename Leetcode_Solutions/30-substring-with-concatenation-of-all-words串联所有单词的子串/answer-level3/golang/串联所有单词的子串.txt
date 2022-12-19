## 思路

此处需要注意有一些重要条件：
- words里的单词长度相同
- 寻找的子串是words里单词包含所有可能的拼接顺序

根据条件，我们可以每次从s中截取固定长度的子串，并判断在这个子串中是否包含了words里所有单词出现的次数（因为顺序不定，只要出现次数相同就可以构造出对应子串）。再根据`words里的单词长度相同`, 我们每次从子串中截取一个单词长度的子串，判断它是否是子串中的单词，这里需要注意匹配到以后应该从这个单词末尾继续匹配，不然会出现单词重叠的情况。



## Code

```
func findSubstring(s string, words []string) (result []int) {
	n := len(words)
	if n == 0 {
		return
	}
	dict := map[string]int{}
	wn := 0
	for _, w := range words {
		dict[w]++
		wn += len(w)
	}
	ns := len(s)
	for i := 0; i < ns-wn+1; i++ {
		if findIndexes(s[i:i+wn], len(words[0]), dict) {
			result = append(result, i)
		}
	}
	return
}

func findIndexes(s string, wl int, dict map[string]int) bool {
	ns := len(s)
	tmp := map[string]int{}
	for i := 0; i < ns-wl+1; i++ {
		k := s[i : i+wl]
		if dict[k] != 0 {
			tmp[k]++
            // 从末尾开始继续匹配，防止单词重叠
			i = i + wl - 1
		}
	}
	for k, v := range dict {
		if tmp[k] != v {
			return false
		}
	}
	return true
}
```
