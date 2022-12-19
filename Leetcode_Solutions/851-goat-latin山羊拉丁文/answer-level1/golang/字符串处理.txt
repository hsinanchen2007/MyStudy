### 解题思路
此处撰写解题思路

### 代码

```golang
func toGoatLatin(S string) string {
	str:=strings.Split(S," ")
	res:=make([]string,0, len(str))
	for i:=0;i< len(str);i++{
		tmp:=[]rune(str[i])
		if len(tmp)>0{
			switch tmp[0] {
			case 'a','e','i','o','u','A','E','I','O','U':
				tmp=append(tmp,'m','a')
				for j:=1;j<=i+1;j++{
					tmp=append(tmp,'a')
				}
				res= append(res, string(tmp))
			default:
				if len(tmp)>1{
					tmp=append(tmp[1:],tmp[0])
				}
				tmp=append(tmp,'m','a')
				for j:=1;j<=i+1;j++{
					tmp=append(tmp,'a')
				}
				res= append(res, string(tmp))
			}
		}
	}
	x:=""
	for _,v:=range res{
		x+=v+" "
	}
	return strings.TrimSpace(x)
}
```