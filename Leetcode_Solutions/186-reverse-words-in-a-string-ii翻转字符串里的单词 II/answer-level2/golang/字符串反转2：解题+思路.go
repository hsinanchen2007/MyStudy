### 解题思路
//思路：
//1，将整个字符串进行反转
//2，再将每个单词进行反转
//3，注意边界条件的处理：最后一个字符的处理

### 代码

```golang
//思路：
//1，将整个字符串进行反转
//2，再将每个单词进行反转
//3，注意边界条件的处理：最后一个字符的处理
func reverseWords(s []byte) {
	if len(s) == 0 {
		return
	}

	reverseString(s)
	fmt.Println(s)
	preIndex := 0
	for index := 0; index < len(s); index++ {
		if s[index] == 32 {
			reverseString(s[preIndex:index])
			preIndex = index + 1
		}

		//这里需要判断末尾的边界
		if index == len(s)-1 {
			reverseString(s[preIndex : index+1])
		}

	}
	fmt.Println(s)
}

func reverseString(s []byte) {
	var (
		front int = 0
		back  int = len(s) - 1
	)

	for {
		if front >= back {
			break
		}

		s[front], s[back] = s[back], s[front]
		front++
		back--
	}

	//return s
}
```