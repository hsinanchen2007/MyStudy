### 解题思路
此处撰写解题思路

### 代码

```golang
func reverseWords(s string) string {
	strSlice:=strings.Split(s," ")
	res:=""
	for j,v:=range strSlice{
		m:=[]rune(v)
		s:=make([]rune,0)
		for i:= len(m)-1;i>=0;i--{
			s= append(s, m[i])
		}
		res+=string(s)
		if j!= len(strSlice)-1{
			res+=" "
		}
	}
	return res
}
```