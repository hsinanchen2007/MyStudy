### 解题思路
此处撰写解题思路

### 代码

```golang
func isLongPressedName(name string, typed string) bool {
	nameRune:=[]rune(name)
	typedRune:=[]rune(typed)
	for len(nameRune)>0{
		if len(typedRune)==0||typedRune[0]!=nameRune[0]{
			return false
		}
		tmp:=make([]rune,0)
		tmp= append(tmp, nameRune[0])
		i:=1
		for ;i< len(nameRune);i++{
			if nameRune[i]==nameRune[i-1]{
				tmp= append(tmp, nameRune[i])
			}else{
				break
			}
		}
		nameRune=nameRune[i:]
		tmp2:=make([]rune,0)
		tmp2=append(tmp2,typedRune[0])
		j:=1
		for ;j< len(typedRune);j++{
			if typedRune[j]==typedRune[j-1]{
				tmp2= append(tmp2, typedRune[j])
			}else{
				break
			}
		}
		typedRune=typedRune[j:]
		if len(tmp2)< len(tmp){
			return false
		}
	}
	return true
}
```