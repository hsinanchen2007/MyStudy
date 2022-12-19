### 解题思路
此处撰写解题思路

### 代码

```golang
func uncommonFromSentences(A string, B string) []string {
	mapA:=make(map[string]int)
	mapB:=make(map[string]int)
	sliceA:=strings.Split(A," ")
	sliceB:=strings.Split(B," ")
	for _,v:=range sliceA{
		if _,ok:=mapA[v];ok{
			mapA[v]++
		}else{
			mapA[v]=1
		}
	}
	for _,v:=range sliceB{
		if _,ok:=mapB[v];ok{
			mapB[v]++
		}else{
			mapB[v]=1
		}
	}
	res:=make([]string,0)
	for k,v:=range mapA{
		if v==1{
			if _,ok:=mapB[k];!ok{
				res= append(res, k)
			}
		}
	}
	for k,v:=range mapB{
		if v==1{
			if _,ok:=mapA[k];!ok{
				res= append(res, k)
			}
		}
	}
	return res
}
```