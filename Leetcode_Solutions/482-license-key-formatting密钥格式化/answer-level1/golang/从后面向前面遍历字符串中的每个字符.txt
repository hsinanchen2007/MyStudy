### 解题思路
此处撰写解题思路

### 代码

```golang
func licenseKeyFormatting(S string, K int) string {
	slice:=[]rune(S)
	fmt.Println(slice)
	res:=make([]rune,0)
	k:=0
	for i:=len(slice)-1;i>=0;i--{
		v:=slice[i]
		if v>=97{
			v-=32
		}
		if v=='-'{
			continue
		}
		res= append([]rune{v}, res...)
		k++
		if k==K{
			res= append([]rune{'-'},res... )
			k=0
		}
	}
	if len(res)==0{
		return ""
	}
	if res[0]=='-'{
		res=res[1:]
	}

	return string(res)
}
```