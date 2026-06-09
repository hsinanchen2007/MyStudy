```
func removeVowels(S string) string {
    for _,value := range "aeiou" {
		S = strings.Replace(S, string(value), "", -1)
	}
	return S
}
```
