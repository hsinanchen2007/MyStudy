### 解题思路
此处撰写解题思路

### 代码

```golang
func reorderLogFiles(logs []string) []string {
	numStr:=make([]string,0)

	secondLetterStr:=make([]string,0)
	helloMap:=make(map[string][]string)
	for _,v:=range logs{
		s:=strings.Split(v," ")
		ss:=""
		for i:=1;i< len(s);i++{
			ss+=" "+s[i]
		}
        //还原除了标识符的字符串，后面排序的时候空格也起到了作用
		ss=strings.TrimSpace(ss)
		if !unicode.IsLetter(rune(s[1][0])){
			numStr= append(numStr, v)
		}else{
			secondLetterStr= append(secondLetterStr, ss)
			helloMap[v]=[]string{s[0],ss}
		}
	}
	sort.Strings(secondLetterStr)

	res1:=make([]string,0)
	for i:=0;i< len(secondLetterStr);i++{
		if i== len(secondLetterStr)-1{
			for k,v:=range helloMap{
				if v[1]==secondLetterStr[i]{
					res1= append(res1, k)
					break
				}
			}
		}else{
			if secondLetterStr[i+1]!=secondLetterStr[i]{
				for k,v:=range helloMap{
					if v[1]==secondLetterStr[i]{
						res1= append(res1, k)
						break
					}
				}
			}else{
                //遍历出所有后面相同的
				tmp:=make([]string,0)
				for k,v:=range helloMap{
					if v[1]==secondLetterStr[i]{
						tmp= append(tmp, k)
					}
				}
                //排序
				for j:=0;j< len(tmp)-1;j++{
					if !(helloMap[tmp[i]][0]<helloMap[tmp[i+1]][0]){
						tmp[i],tmp[i+1]=tmp[i+1],tmp[i]
					}
				}
				res1=append(res1,tmp...)
                //因为默认待了 i++，所以要减去1
				i+= len(tmp)-1
			}
		}

	}

	return append(res1,numStr...)
}

```