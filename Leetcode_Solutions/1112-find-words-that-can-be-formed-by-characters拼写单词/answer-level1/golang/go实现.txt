### 解题思路
1、使用map 映射数量

### 代码

```golang
package main

import "fmt"

func countCharacters(words []string, chars string) int {
	var byteCount [26]int
	for _, char := range chars {
		byteCount[char-'a']++
	}
	var resCount int
	for _, word := range words {
		bc, match := byteCount, true
		for _, char := range word {
			if bc[char-'a'] <= 0 {
				match = false
				break
			}
			bc[char-'a']--
		}
		if match == true {
			resCount = resCount + len(word)
		}
	}
	return resCount
}
```