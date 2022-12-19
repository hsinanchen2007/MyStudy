#### 解题思路

解题思路如参考代码注释所示


#### 参考代码

```go
func shortestCompletingWord(licensePlate string, words []string) string {
	lengthWords := len(words)
	min:= 16
	minWord := ""

	//依次遍历取出words里的每个单词
	for i:=0;i<lengthWords;i++ {
		wordLength := len(words[i])
		list := make([]int,26)
		
		//如果该单词比当前最短完整词的长度长则舍去
		if wordLength<min {

			//依次将每个单词转换到长度为26的哈希表里(切片做哈希表)
			for j:=0;j<wordLength;j++ {
				list[words[i][j]-'a']++
			}

			//依次遍历比较牌照中的字母是否都在该单词里
			if  compare(list,licensePlate) {

				//如果存在则更新最短完整词和最短长度
				min = wordLength
				minWord = words[i]
			}
		}
	}
	return minWord
}

func compare(list []int, licensePlate string) bool {
	for i:=0;i<len(licensePlate);i++ {
		if letter := licensePlate[i];unicode.IsLetter(rune(letter)){
			if list[(letter | 32)-'a'] <= 0 {
				return false
			}
			list[(letter | 32)-'a']--
		}
	}
	return true
}

```

**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**

