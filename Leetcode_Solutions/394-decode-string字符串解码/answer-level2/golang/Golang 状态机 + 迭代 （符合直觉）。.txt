字符串总可以转换成“头 + 重复数字 + 重复部分 + 尾”这4部分。
其中头可能是空，
如果数字是空，那么重复部分也是空。
重复部分又可以再次分解成这4部分（迭代）。
尾也可以再次分解成这4部分（迭代））。
最后根据这4部分的信息组合出最后的结果。

```

import (
	"fmt"
	"strconv"
)

const (
	headState = iota
	numState
	repeatState
	tailState
)

func decodeString(s string) string {
	if s == "" {
		return ""
	}
	bs := []byte(s)
	ret := make([]byte, 0)

	headBytes := make([]byte, 0)
	numBytes := make([]byte, 0)
	repeatBytes := make([]byte, 0)
	tailBytes := make([]byte, 0)
	bracketCount := 0
	state := headState
	for _, b := range bs {
		switch state {
		case headState:
			switch {
			case (b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'F'):
				headBytes = append(headBytes, b)
			case b >= '0' && b <= '9':
				numBytes = append(numBytes, b)
				state = numState
				break
			default:
				fmt.Printf("bad char %c at head state\n", b)
			}
		case numState:
			switch {
			case b >= '0' && b <= '9':
				numBytes = append(numBytes, b)
			case b == '[':
				bracketCount = 1
				state = repeatState
				break
			default:
				fmt.Printf("bad char %c at num state\n", b)
			}
		case repeatState:
			if b == '[' {
				bracketCount++
			}
			if b == ']' {
				bracketCount--
				if bracketCount == 0 {
					state = tailState
					break
				}
			}
			repeatBytes = append(repeatBytes, b)
		case tailState:
			tailBytes = append(tailBytes, b)
		}
	}
	// fmt.Printf("head = %s, num = %s, repeat = %s, tail = %s\n", string(headBytes), string(numBytes), string(repeatBytes), string(tailBytes))
	ret = append(ret, headBytes...)
	num, _ := strconv.Atoi(string(numBytes))
	for i:=0; i < num; i++ {
		r := decodeString(string(repeatBytes))
		ret = append(ret, []byte(r)...)
	}
	t := decodeString(string(tailBytes))
	ret = append(ret, []byte(t)...)
	// fmt.Printf("ret = %s\n", string(ret))
	return string(ret)
}
```
