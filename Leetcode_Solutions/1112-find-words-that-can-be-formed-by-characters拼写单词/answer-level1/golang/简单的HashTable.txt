```
package main

import "fmt"

func countCharacters(words []string, chars string) int {
	// hashTable
	var hashTable = [26]int{}
	count := 0
	for i := 0; i < len(chars); i++ {
		hashTable[chars[i]-'a']++
	}
	for i := 0; i < len(words); i++ {
		tempTable := hashTable
		temp := words[i]
		//fmt.Println(temp)
		flag := true
		for j := 0; j < len(temp); j++ {
			if tempTable[temp[j]-'a'] > 0 {
				tempTable[temp[j]-'a']--
			} else {
				flag = false
				break
			}
		}
		if flag == true {
			count += len(temp)
		}
	}
	return count
}

func main() {
	words := []string{"hello", "world", "leetcode"}
	chars := "welldonehoneyr"
	ans := countCharacters(words, chars)
	fmt.Println(ans)
}

```

