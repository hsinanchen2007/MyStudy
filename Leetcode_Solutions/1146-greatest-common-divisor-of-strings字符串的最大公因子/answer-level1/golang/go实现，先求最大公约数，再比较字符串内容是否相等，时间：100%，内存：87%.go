代码如下：
```
	if len(str1) == 0 || len(str2) == 0 {
		return ""
	}
	s1:=len(str1)
	s2:=len(str2)
	if s1+s2!=s2+s1{
		return ""
	}
	if s1<s2{
		return gcdOfStrings(str2,str1)
	}
	if s1==s2{
		if str1==str2{
			return str1
		}
		return ""
	}
	return gcdOfStrings(str1[s2:],str2)
```
