```
func canPermutePalindrome(s string) bool {
	maps := map[int]int{}
	for i:= 0;i < len(s);i++{
		maps[int(s[i]- 'a')]++
	}
	counts := 0
	for _,v := range  maps{
		if v %2 == 1{
			counts++
		}
	}
	return  counts <= 1
}
```
