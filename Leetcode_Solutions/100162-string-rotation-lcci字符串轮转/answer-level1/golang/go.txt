```
func isFlipedString(s1 string, s2 string) bool {
	n1,n2 := len(s1) ,len(s2)
	if n1 != n2{
		return  false
	}
	return  n1 == n2 && strings.Contains(s2+s2,s1)
}
```
