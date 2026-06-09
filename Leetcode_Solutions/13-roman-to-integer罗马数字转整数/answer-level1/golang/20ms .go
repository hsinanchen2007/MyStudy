```
func romanToInt(s string) int {
    var re int
    m := map[string]int{
        "M" : 1000,
        "CM" : 900,
        "D" : 500,
        "CD" : 400,
        "C" : 100,
        "XC" : 90,
        "L" : 50,
        "XL" : 40,
        "X" : 10,
        "IX" : 9,
        "V" : 5,
        "IV" : 4,
        "I" : 1,
    }
    for i := 0; i < len(s); {
        if i < len(s) - 1 {
			if r,ok := m[s[i:i+2]]; ok {
				re += r
				i = i+2
			}else{
				if r,ok := m[s[i:i+1]]; ok {
					re += r
					i = i+1
				}
			}
		}else{
			if r,ok := m[s[i:i+1]]; ok {
				re += r
				i = i+1
			}
		}
    }
    return re
}
```


