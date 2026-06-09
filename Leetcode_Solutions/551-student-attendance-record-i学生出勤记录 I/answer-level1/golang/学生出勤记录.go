### 解题思路
此处撰写解题思路

### 代码

```golang
func checkRecord(s string) bool {
	sMap:=make(map[rune]int)
	LFlag:=strings.Contains(s,"LLL")
	for _,v:=range s{
		if _,ok:=sMap[v];ok{
			sMap[v]++
		}else{
			sMap[v]=1
		}
	}

	if sMap['A']<=1&&!LFlag{
		return true
	}

	return false
}
```