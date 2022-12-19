一个模糊点就是，如果空格数量不能整除要怎么处理，例如：

- 8 个空格分 3 份，应该是 [3, 3, 2] 而不是 [4, 2, 2]
- 10 个空格分 4 份，应该是 [3, 3, 2, 2]，而不是 [4, 2, 2, 2]

```
import (
	"bytes"
	"strings"
)

var space = uint8(' ')

func fullJustify(words []string, maxWidth int) (rst []string) {
	var subWords = []string{}
	var subLen = 0
	for i := 0; i < len(words); i++ {
		if subLen+len(words[i])+len(subWords) > maxWidth {
			rst = append(rst, adjustWords(subWords, subLen, maxWidth))
			subWords = []string{words[i]}
			subLen = len(words[i])
		} else {
			subWords = append(subWords, words[i])
			subLen += len(words[i])
		}
	}

	if subLen != 0 {
		builder := strings.Builder{}
		for i := 0; i < len(subWords)-1; i++ {
			builder.Write([]byte(subWords[i]))
			builder.Write([]byte{space})
		}
		builder.Write([]byte(subWords[len(subWords)-1]))
		for i := subLen + len(subWords) - 1; i < maxWidth; i++ {
			builder.Write([]byte{space})
		}
		rst = append(rst, builder.String())
	}

	return
}

func adjustWords(words []string, subLen, maxWidth int) string {
	if len(words) == 1 {
		return singleWords(words, maxWidth)
	}
	spaceLen := maxWidth - subLen
	subSpaceLen := make([]int, len(words)-1)
	count := spaceLen % (len(words) - 1)
	for i := 0; i < len(words)-1; i++ {
		subSpaceLen[i] = spaceLen / (len(words) - 1)
		if i < count {
			subSpaceLen[i]++
		}
	}

	builder := strings.Builder{}
	for i := 0; i < len(words); i++ {
		builder.Write([]byte(words[i]))
		if i < len(subSpaceLen) {
			builder.Write(bytes.Repeat([]byte{space}, subSpaceLen[i]))
		}
	}

	return builder.String()
}

func singleWords(words []string, maxWidth int) string {
	return words[0] + strings.Repeat(string(space), maxWidth-len(words[0]))
}
```
