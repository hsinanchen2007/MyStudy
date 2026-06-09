1.使用栈实现
2.每个字符入一次栈，如果匹配就出栈
3.最后要求栈为空


```

func isValid(s string) bool {
	var lens =strings.Count(s,"")-1
	if lens==0{
		return true
	}
	var arr []string
	var mp = map[string]string{")":"(","]":"[","}":"{"}
	for _,v:=range s{
		if mv,ok:=mp[string(v)];ok{
			if (len(arr)==0) || (mv!=PopS(&arr)){
				return false
			}
		}else {
			arr=append(arr,string(v))
		}
	}
	return len(arr)==0
}

func PopS(s *[]string) string {
	if len(*s) == 0 {
		return ""
	}
	lens := len(*s)
	v := (*s)[lens-1]
	*s = (*s)[:lens-1]
	return v
}
```
