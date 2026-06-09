````go []

//有效的括号
func IsValid(s string) bool {
	length := len(s)
	if length%2 != 0  {
		return false
	}
	if  length ==0 {
		return true
	}
	tmp := []byte{s[0]}
	for i := 1; i < length; i++ {
		switch s[i] {
		case '(':
			tmp = append(tmp, s[i])
		case '{':
			tmp = append(tmp, s[i])
		case '[':
			tmp = append(tmp, s[i])
		case ')':
			if tmp[len(tmp)-1] != '(' {
				return false
			}
			//闭合就消除
			tmp = tmp[:len(tmp)-1]
		case '}':
			if tmp[len(tmp)-1] != '{' {
				return false
			}
			//闭合就消除
			tmp = tmp[:len(tmp)-1]
		case ']':
			if tmp[len(tmp)-1] != '[' {
				return false
			}
			//闭合就消除
			tmp = tmp[:len(tmp)-1]
		default:
			return false
		}
	}
	if  len(tmp)!=0 {
		return false
	}
	return true
}

```

