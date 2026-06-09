### 解题思路
此处撰写解题思路

### 代码

```golang
func romanToInt(s string) int {
	romanMap := map[string]int{
		"I": 1,
		"V": 5,
		"X": 10,
		"L": 50,
		"C": 100,
		"D": 500,
		"M": 1000,
		"IV": 4,
		"IX": 9,
		"XL": 40,
		"XC": 90,
		"CD": 400,
		"CM": 900,
	}
	rlt := 0
	for i := 0; i < len(s); {
		okO := false
		vO := 0
		if i+2 <= len(s) {
			v,ok :=romanMap[string(s[i:i+2])]
			vO = v
			okO = ok
		}
		if i+1 < len(s) && okO {
			rlt += vO
			i += 2
		} else {
			rlt += romanMap[string(s[i])]
			i++
		}
	}
	return rlt
}

```