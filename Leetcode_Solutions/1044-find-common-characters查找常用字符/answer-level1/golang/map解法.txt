### 解题思路
此处撰写解题思路

### 代码

```golang
func commonChars(A []string) []string {
	resMap:=make(map[rune]int)
	for i:=0;i< len(A[0]);i++{
		x:=[]rune(A[0])
		resMap[x[i]]++
	}
	for _,v:=range A{
		a:=[]rune(v)
		tmp:=make(map[rune]int)
		for _,r:=range a{
			tmp[r]++
		}
		for k,_:=range resMap{
			if tmp[k]==0{
				delete(resMap,k)
			}
		}
		for k,u:=range tmp{
			if resMap[k]!=0&&resMap[k]>u{
				resMap[k]=u
			}
		}
	}
	res:=make([]string,0)
	for k,v:=range resMap{
		for v>0{
			res= append(res, string(k))
			v--
		}
	}
	return res
}

```