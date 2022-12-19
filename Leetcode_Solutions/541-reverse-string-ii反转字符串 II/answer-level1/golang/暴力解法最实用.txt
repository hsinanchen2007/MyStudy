### 解题思路
此处撰写解题思路

### 代码

```golang
func reverseStr(s string, k int) string {
	n:= len(s)/(2*k)
	m:= len(s)%(2*k)
	resSlice:=make([]rune,0)
	strSlice:=[]rune(s)
	for i:=1;i<=n;i++{
		tmp:=make([]rune,0)
		for j:=2*i*k-k-1;j>=2*i*k-2*k;j--{
			tmp= append(tmp,strSlice[j] )
			fmt.Printf("%c",tmp)
		}
		tmp=append(tmp,strSlice[(2*i*k-k):2*i*k]...)
		resSlice=append(resSlice,tmp...)
	}
	last:=make([]rune,0)
	//如果最后的m个 长度小于k，则 反转所有的m个字符
	if m<k{
		for i:= len(strSlice)-1;i>= len(strSlice)-m;i--{
			last= append(last, strSlice[i])
		}
	}else{
		x:=make([]rune,0)
		for i:= len(strSlice)-m+k-1;i>= len(strSlice)-m;i--{
			x= append(x, strSlice[i])
		}
		last=append(x,strSlice[(len(strSlice)-m+k):]...)
	}
	resSlice= append(resSlice, last...)
	return string(resSlice)
}

```