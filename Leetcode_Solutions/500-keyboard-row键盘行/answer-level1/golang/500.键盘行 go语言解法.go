### 解题思路

简单粗暴的方法：
将三行字母放在 字符串数组中，并用两个标志位来表示每个单词首字母在哪一行以及当前遍历的字母在哪一行，如果两个标志位不相等，则跳过这个单词遍历下一个单词，若所有字母 都在一行上，就把 该单词添加进结果数组。

### 代码

```golang
func findWords(words []string) []string {
	str := []string{"qwertyuiopQWERTYUIOP","asdfghjklASDFGHJKL","zxcvbnmZXCVBNM"}
	res := []string{}
	flag1 := 0
	flag2 := 0
	for i := 0;i < len(words);i++ {
		if len(words[i]) == 1 {
			res = append(res,words[i])
			continue
		}
		if strings.Contains(str[0],string(words[i][0])) {
			flag1 = 0
		}else if strings.Contains(str[1],string(words[i][0])) {
			flag1 = 1
		}else {
			flag1 = 2
		}
		for j := 1;j < len(words[i]);j++ {

			if strings.Contains(str[0],string(words[i][j])) {
				flag2 = 0
			}else if strings.Contains(str[1],string(words[i][j])) {
				flag2 = 1
			}else {
				flag2 = 2
			}
			if flag2 != flag1 {
				break
			}
		}
		if flag2 == flag1 {
			res = append(res,words[i])
		}
	}
	return res
}
```