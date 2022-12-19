### 解题思路
此处撰写解题思路

### 代码

```golang
func buddyStrings(A string, B string) bool {
	if !(len(A)== len(B)&& len(A)>1){
		return false
	}
	runeA:=[]rune(A)
	mapA:=make(map[rune]int)
	for i:=0;i< len(runeA);i++{
		if _,ok:=mapA[runeA[i]];ok{
			mapA[runeA[i]]++
		}else{
			mapA[runeA[i]]=1
		}
	}
	if A==B{
		flag:=false
		for _,v:=range mapA{
			if v>=2{
				flag=true
				break
			}
		}
		if flag{
			return true
		}
	}
	count:=0
	index:=make([]int,0)
	for i:=0;i< len(A);i++{
		if A[i]!=B[i]{
			count++
			if count>2{
				return false
			}
			index= append(index, i)
		}
	}
	if len(index)!=2{
		return false
	}

	runeA[index[0]],runeA[index[1]]=runeA[index[1]],runeA[index[0]]
	return string(runeA)==B
}

```