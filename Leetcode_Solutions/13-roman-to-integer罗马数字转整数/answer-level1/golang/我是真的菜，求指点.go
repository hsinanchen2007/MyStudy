### 解题思路
此处撰写解题思路

### 代码

```golang
func romanToInt(s string) int {
	var I, V, X, L, C, D, M, sum,pop int
	m := map[int]string{}
	for _, v := range s {
		switch string(v) {
		case "I":
			I++
		case "V":
			V++
		case "X":
			X++
		case "L":
			L++
		case "C":
			C++
		case "D":
			D++
		case "M":
			M++
		}
	}
	for i, v := range s {
		m[i] = string(v)
		if (string(v) == "V" || string(v) == "X") && m[i-1] == "I" {
			pop += 2
		}
		if (string(v) == "L" || string(v) == "C") && m[i-1] == "X" {
			pop += 20
		}
		if (string(v) == "D" || string(v) == "M") && m[i-1] == "C" {
			pop += 200
		}
	}
    sum = I*1+V*5+X*10+L*50+C*100+D*500+M*1000 - pop
    return sum
}
```