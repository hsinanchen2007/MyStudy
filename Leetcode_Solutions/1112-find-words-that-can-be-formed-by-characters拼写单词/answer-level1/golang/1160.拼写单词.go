### 解题思路

用数组存放chars中每个字母出现的次数，遍历words中的每个单词，如果出现每个单词张字母的数量都小于等于该字母在chars中出现的次数，则把该单词的长度加进结果即可。

### 代码

```golang
func countCharacters(words []string, chars string) int {
	sto := make([]byte,26)
	tmp := []byte{}
	ans := 0
	for i := 0;i < len(chars);i++ {
		sto[int(chars[i]) - 97]++
	}
	for i := 0;i < len(words);i++ {
		tmp := append(tmp,sto...)
		for j := 0;j < len(words[i]);j++ {
			if tmp[int(words[i][j]) - 97] == 0 {
				break
			}
			tmp[int(words[i][j]) - 97]--
			if j == len(words[i]) - 1 {
				ans += len(words[i])
			}
		}
	}
	return ans
}
```