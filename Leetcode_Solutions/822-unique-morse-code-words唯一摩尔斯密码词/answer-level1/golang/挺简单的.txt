### 解题思路
此处撰写解题思路

### 代码

```golang
func uniqueMorseRepresentations(words []string) int {
	a := [26]string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}
	m:=make(map[string]int)
	for i:=0;i< len(words);i++{
		s:=""
		for j:=0;j< len(words[i]);j++{
			s+=a[words[i][j]-'a']
		}
		m[s]=1
	}
	
	return len(m)
}
```