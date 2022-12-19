### 解题思路

![Q{IBQ0L3K~X@6}W\[269L8IJ.png](https://pic.leetcode-cn.com/9c62035da2e2676b716b2085642d9a26e6b2f42e4d8566f75c1848a3861865f0-Q%7BIBQ0L3K~X@6%7DW%5B269L8IJ.png)


### 代码

```golang
func romanToInt(s string) int {
	var result int
	temp := 0
	for i:=len(s)-1; i>=0; i--{
		num := getNumber(string(s[i]))
		if num < temp && (num == 1 || (num == 10) || num == 100){
			result -= num
		}else{
			result += num
		}
		temp = num
	}
	return result
}

func getNumber(s string) int{
	switch s {
	case "I": return 1
	case "V": return 5
	case "X": return 10
	case "L": return 50
	case "C": return 100
	case "D": return 500
	case "M": return 1000
	default: return 0
	}
}
```