```
func romanToInt(s string) int {
    sum:=0
	b:=map[string]int{"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}

	for i:=0;i<len(s);i++{
        sum+=b[string(s[i])]
	}
	for i:=0;i<len(s)-1; {
        base:=b[string(s[i])]
		j := i + 1
		if b[string(s[j])] == 5*base || b[string(s[j])] == 10*base {
				sum =sum-2*base
				i+=2
		}else{
				i++
		}
    }	
	

  return sum
}
```
