### 解题思路
此处撰写解题思路

### 代码

```golang
func shortestToChar(S string, C byte) []int {
	str:=[]byte(S)
	res:=make([]int,0)
	for i:=0;i< len(S);i++{
		m:= len(str)
		n:= len(str)
		for j:=i;j>=0;j--{
			if str[j]==C{
				m=i-j
				break
			}
		}
		for k:=i;k< len(str);k++{
			if str[k]==C{
				n=k-i
				break
			}
		}
		if m<n{
			res=append(res, m)
		}else{
			res=append(res,n)
		}
	}
	return res
}
```