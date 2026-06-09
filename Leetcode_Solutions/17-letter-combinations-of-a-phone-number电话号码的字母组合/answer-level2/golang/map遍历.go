### 解题思路
此处撰写解题思路

### 代码

```golang
func letterCombinations(digits string) []string {
	dict := map[uint8][]string{
		2:{"a", "b", "c"},
		3:{"d", "e", "f"},
		4:{"g", "h", "i"},
		5:{"j", "k", "l"},
		6:{"m", "n", "o"},
		7:{"p", "q", "r", "s"},
		8:{"t", "u", "v"},
		9:{"w", "x", "y", "z"},
	}

	var result []string
	if len(digits) == 0 {
		return result
	}
	result = append(result, "")
	length := len(digits)

	for i := 0; i < length; i++  {
		letters := dict[digits[i] - '0']

		size := len(result)
		for j := 0; j < size; j++  {
			tmp := result[0]
			result = result[1:]

			for h := 0; h < len(letters) ; h++  {
				result = append(result, tmp+letters[h])
			}
		}
	}

	return result
}

```