### 解题思路
此处撰写解题思路

第i行的第z个 是字符串中第 i+ z(2*numRows - 2) ,i+ z(2*numRows - 2)+2*numRows - 2 - i*2 个字符构成

golang中生成新的字符串不能使用 append，会分配失败

### 代码

```golang
func convert(s string, numRows int) string {
	if numRows ==1{
		return s
	}
	sLen := len(s)
	sb := make([]byte, sLen)

	k := 0
	for i := 0; i < numRows; i++ {

		step := 2*numRows - 2 - i*2

		for j := i; j < sLen; j = j + 2*numRows - 2 {

			// sb = append(sb,(s[j]))
			if j<sLen{
				sb[k] = s[j]
				k = k + 1
			}

			if i != 0 && i != numRows-1 && j+step < sLen {

				// sb = append(sb, (s[j+step]))
				sb[k] = s[j+step]
				k = k + 1
			}

		}

	}

	return string(sb)
}
```