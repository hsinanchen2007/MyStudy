
```
func compressString(S string) string {
	if len(S)==0{
		return S
	}
	t:=S[0]
	count:=0
	sb:=strings.Builder{}
	for i:=0;i<len(S);i++{
		if S[i]==t{
			count+=1
			continue
		}
		sb.WriteByte(t)
		sb.WriteString(strconv.Itoa(count))
		t=S[i]
		count=1
	}
	sb.WriteByte(t)
	sb.WriteString(strconv.Itoa(count))
    if len(sb.String())>=len(S){
        return S
    }
	return sb.String()
}
```
