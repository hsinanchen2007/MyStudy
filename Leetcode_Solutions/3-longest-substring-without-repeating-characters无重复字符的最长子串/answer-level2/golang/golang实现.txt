```
func GetLongestStringLength(s string)(count int){
	strSlice := ""
	tmp := ""
	for i:=0; i < len(s); i++ {
		if len(tmp) >= 1 {
			if string(tmp[0]) == string(s[i]) {
				tmp = tmp[1:] + string(s[i])
			} else if b,idx := HasString(string(s[i]),tmp);b {
				tmp = tmp[idx+1:] + string(s[i])
			} else {
				tmp = tmp + string(s[i])
			}
		} else {
			tmp = string(s[i])
		}
		if len(tmp) > len(strSlice) {
			strSlice = tmp
		}
	}
	return len(strSlice)
}

func HasString(s string, str string) (b bool, idx int) {
	for i := 0; i < len(str); i++ {
		if s == string(str[i]) {
			return true,i
		}
	}
	return false,-1
}
```
