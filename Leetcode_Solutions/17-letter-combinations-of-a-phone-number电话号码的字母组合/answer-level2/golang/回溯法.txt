### 解题思路
![image.png](https://pic.leetcode-cn.com/1ce24e708b07203ade115aa90b6d18987815b99c5ec0f39ade42372b34e9c449-image.png)

### 代码

```golang
var chars []string

func letterCombinations(digits string) []string {
	chars = make([]string, 0, len(digits)*len(digits))
	// 95 96 97
	s := make([]rune, 0, len(digits))
	arrange(digits, s)
	return chars
}

func arrange(digits string, s []rune) {

	if len(digits) == 0 {
		return
	}

	max := 3

	if digits[0] == 55 || digits[0] == 57 {
		max = 4
	}

	for i := 0; i < max; i++ {
		letter := rune(97+i) + rune((digits[0]-50)*3)
		if digits[0] > 55 {
			letter += 1
		}

		s = append(s, letter)
		arrange(digits[1:], s)

		if len(s) == cap(s) {
			temp := make([]rune, len(s))
			copy(temp, s)
			chars = append(chars, string(temp))
		}
		s = s[:len(s)-1]
	}
}
```