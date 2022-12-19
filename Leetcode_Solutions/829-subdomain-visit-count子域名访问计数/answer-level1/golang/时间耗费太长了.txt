### 解题思路
此处撰写解题思路

### 代码

```golang
func subdomainVisits(cpdomains []string) []string {
	m:=make(map[string]int)
	for i:=0;i< len(cpdomains);i++{
		str:=strings.Split(cpdomains[i]," ")
		s:=strings.Split(str[1],".")
		tmp:=s[len(s)-1]
		n,_:=strconv.Atoi(str[0])
		if _,ok:=m[tmp];ok{
			m[tmp]+=n
		}else{
			m[tmp]=n
		}
		for j:=len(s)-2 ;j>=0;j--{
			tmp=s[j]+"."+tmp
			if _,ok:=m[tmp];ok{
				m[tmp]+=n
			}else{
				m[tmp]=n
			}
		}
	}
	res:=make([]string,0, len(m))
	for k,v:=range m{
		r:=strconv.Itoa(v)+" "+k
		res= append(res, r)
	}
	return res
}
```