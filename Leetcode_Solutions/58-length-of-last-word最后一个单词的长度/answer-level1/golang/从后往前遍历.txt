### 解题思路
此处撰写解题思路

### 代码

```golang
func lengthOfLastWord(s string) int {
	length := 0
	for i := len(s) - 1; i >= 0; i-- {
		if string(s[i]) != " " {
			length += 1
		}else {
			if length!=0{
				break
			}
			length=0
		}
	}
	return length
}
```