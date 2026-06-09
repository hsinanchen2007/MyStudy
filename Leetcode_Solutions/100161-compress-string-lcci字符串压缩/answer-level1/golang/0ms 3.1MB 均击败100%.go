### 解题思路
此处撰写解题思路

### 代码

```golang

func compressString(S string) string {

	// str := []byte("0123456789")
	count := len(S)
	if count <= 2 {
		return S
	}
	pre := S[0]
	preCount := 1
	newS := make([]byte, 0)
	newSLen := 0
	for i := 1; i < count; i++ {
		if S[i] != pre {
			newS = append(newS, pre)
			newS = append(newS, []byte(strconv.Itoa(preCount))...)
			pre = S[i]
			preCount = 1
			newSLen = newSLen + 2
			if newSLen >= count {
				return S
			}
		} else {
			preCount++
		}
	}
	newS = append(newS, pre)
	newS = append(newS, []byte(strconv.Itoa(preCount))...)
	newSLen = newSLen + 2
	if newSLen >= count {
		return S
	}

	return string(newS)

}

```