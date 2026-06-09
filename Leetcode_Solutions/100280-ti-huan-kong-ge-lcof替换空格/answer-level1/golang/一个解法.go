```
func replaceSpace(s string) string {
    if s == ""{
        return ""
    }
    tmpStr := ""
	for i:=0; i< len(s); i++ {
		if string(s[i]) == " " {
			tmpStr = tmpStr + "%20"
		}else {
			tmpStr = tmpStr + string(s[i])
		}
	}
    return tmpStr
}
```
