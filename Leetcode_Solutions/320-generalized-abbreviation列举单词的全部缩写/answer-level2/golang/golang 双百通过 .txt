### 解题思路
此处撰写解题思路
暴力循环 把每个数字的二进制转化成对应的单词  bit位0标识无替换 1标识需要替换
注意对连续1的处理

### 代码

```golang

func generateAbbreviations(word string) []string {
	sb := []byte(word)
	length := uint(len(sb))
	if length == 0 {
		return []string{""}
	}

	count := int(math.Pow(float64(2), float64(length)))
	r := make([]string, 0, count)
	r = append(r, word)
	r = append(r, strconv.Itoa(int(length)))
	for i := 1; i < count-1; i++ {
		t := make([]byte, length)
		for j := uint(0); j < length; j++ {
			shiftStep := length - j - 1
			tmp := i >> shiftStep
			if tmp&1 == 1 {
				t[j] = 1
			} else {
				t[j] = sb[j]
			}
		}

		preIndex := -1
		lastIndex := -1
		nt := make([]byte, 0, length)
		for x := 0; x < int(length); x++ {
			if t[x] == 1 {
				if preIndex > -1 {
					lastIndex = x
					continue
				}
				if preIndex == -1 {
					preIndex = x
					lastIndex = x
					continue
				}
			} else {
				if lastIndex-preIndex > 0 {
					b := []byte(strconv.Itoa(lastIndex - preIndex + 1))
					nt = append(nt, b...)
				} else if lastIndex-preIndex == 0 && preIndex != -1 {
					nt = append(nt, '1')
				}
			}
			nt = append(nt, t[x])
			preIndex = -1
			lastIndex = -1
		}

		if lastIndex-preIndex > 0 {
			b := []byte(strconv.Itoa(lastIndex - preIndex + 1))
			nt = append(nt, b...)
		} else if lastIndex-preIndex == 0 && preIndex != -1 {
			nt = append(nt, '1')
		}

		r = append(r, string(nt))
	}

	return r
}

```