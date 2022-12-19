```
import "strings"

func CheckPermutation(s1 string, s2 string) bool {
    if len(s1) != len(s2) {return false}
	for _, v := range s1 {
		s1 = strings.ReplaceAll(s1, string(v), "")
		s2 = strings.ReplaceAll(s2, string(v), "")
		if len(s1) != len(s2) {	return false}
	}
	return true
}
```


