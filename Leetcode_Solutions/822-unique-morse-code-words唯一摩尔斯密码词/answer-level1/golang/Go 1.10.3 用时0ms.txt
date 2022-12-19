### 解题思路
分两步处理，第一步先把单词翻译成摩斯密码，第二步看看有多少种不一样的摩斯密码。写的时候比较懒，直接拷贝了题中的摩斯密码放在数组里。

感觉上如果第一步和第二步都用map会快一些。

### 代码

```golang
func uniqueMorseRepresentations(words []string) int {
    var morseCode = [...]string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}
	mIndex := 97
	morseMap := make(map[int]string)
	for _, v := range morseCode {
		morseMap[mIndex] = v
		mIndex++
	}

	wMorse := make([]string, 0)

	for _, vw := range words {
		inMorse := ""
		for _, vs := range vw {
			inMorse = inMorse + morseMap[int(vs)]
		}

		if len(wMorse) == 0 {
			wMorse = append(wMorse, inMorse)
		} else {
			flag := false
			for _, vwm := range wMorse {
				if vwm == inMorse {
					flag = true
				}
			}
			if flag == false {
				wMorse = append(wMorse, inMorse)
			}
		}
	}
	return len(wMorse)
}
```