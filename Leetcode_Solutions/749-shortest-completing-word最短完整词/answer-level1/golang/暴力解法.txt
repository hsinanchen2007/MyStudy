### 解题思路
此处撰写解题思路

### 代码

```golang
func shortestCompletingWord(licensePlate string, words []string) string {
	lic:=[]rune(licensePlate)
	
	res:=""
	index:= len(words)-1
	for i:=0;i< len(words);i++{
		str:=[]rune(strings.ToUpper(words[i]))
		if helpShortestCompletingWord(lic,str){
			if len(res)==0{
				res=words[i]
				index=i
			}else{
				if len(res)> len(words[i]){
					res=words[i]
					index=i
				}
			}

		}
	}
	return words[index]
}

func helpShortestCompletingWord(lic,str []rune)bool{
	for j:=0;j< len(lic);j++{
		if unicode.IsLetter(lic[j]){
			//v是变为大写之后的拍照上的字母
			v:=lic[j]
			if lic[j]>=97{
				v-=32
			}
			flag:=false
			for k:=0;k< len(str);k++{
				if v==str[k]{
					flag=true
					str=append(str[:k],str[k+1:]...)
					break
				}
			}
			if !flag{
				return false
			}
		}
	}
	return true
}

```