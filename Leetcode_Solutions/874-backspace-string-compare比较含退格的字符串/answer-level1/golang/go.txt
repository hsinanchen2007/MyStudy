### 解题思路
此处撰写解题思路

### 代码

```golang
func backspaceCompare(S string, T string) bool {
	s:=[]rune(S)
	t:=[]rune(T)
	x:=make([]rune,0)
	y:=make([]rune,0)
	for i:=0;i< len(s);i++{
		if s[i]!='#'{
			x= append(x, s[i])
		}else{
            if len(x)>0{
                x=x[:len(x)-1]
            }
			
		}
	}
	for j:=0;j< len(t);j++{
		if t[j]!='#'{
			y= append(y, t[j])
		}else{
            if len(y)>0{
                y=y[:len(y)-1]
            }
			
		}
	}
	return string(x)==string(y)
}
```