使用了栈，其实就是括号匹配的进阶版

```golang
func isValid(S string) bool {
	var res []byte
	if len(S)%3!=0{
		return false
	}
	for i:=0;i<len(S);i++{
		if S[i]=='a'{
			res=append(res,'a')
		}
		if S[i]=='b'{
			if len(res)==0 {
				return false
			}
			res=append(res,'b')
		}
		if S[i]=='c'{
			if len(res)<2||res[len(res)-1]!='b'||res[len(res)-2]!='a'{
				return false
			}
			res=res[:len(res)-2]
		}
	}
	if len(res)==0{
		return true
	}
	return false
}
```