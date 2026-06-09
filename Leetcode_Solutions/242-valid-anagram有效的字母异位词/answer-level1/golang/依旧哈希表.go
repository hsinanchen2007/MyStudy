是不是异位词，除了两个字符串的长度需要一致外，还需要它们的字符出现的个数和种类一样。

使用哈希表来解题，字符种类作为键，字符出现数量作为值。

```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
        return false
    }
	ht := make(map[rune]int, len(s))
	for _, ch := range s {
		ht[ch]++
	}
	for _, ch := range t {
		ht[ch]--
	}
	for _, num := range ht {
		if num != 0 {
			return false
		}
	}

	return true
}
```

一开始想把前两个循环给合并，如果出现的字符都是在 ASCII 表中的，没问题，但是如果出现 UNICODE 字符，比如汉字，就会有问题，因为字符集会存在变长字节的情况，所以对 s 字符串的 range 循环并不一一对应着 t 字符串的每个字符，所以不能将这两个循环合并简化。
