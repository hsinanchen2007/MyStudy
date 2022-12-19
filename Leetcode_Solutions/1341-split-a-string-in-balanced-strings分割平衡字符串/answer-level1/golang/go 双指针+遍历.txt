```
func balancedStringSplit(s string) int {
	l,r,c := 0,0,0
	for _,v := range s{
		if v == 'L'{
			l++
		}
		if v == 'R'{
			r++
		}
		if l == r{
			l = 0
			r =0
			c = c +1
		}
	}
	return  c
}
```
