### 解题思路
数字转换技巧： 对于 “2345”  
a = 2   
a = 2 * 10 + 3  
a = (2 * 10 + 3) * 10 + 4  
a = ((2 * 10 + 3) * 10 + 4) * 10 + 5  

简化后：  
a = 2  
a = a * 10 + 3  
a = a * 10 + 4  
a = a * 10 + 5  

累加a的过程中，发现a溢出后，立即返回。   

对于00000000000000022222 类似的输入， 如上的转换技巧，有效数字前任意位数的0不会对结果产生影响。  


### 代码

```golang
func myAtoi(str string) int {
   symboled := false
	positive := true
	numbered := false
	sum := 0
	max := (1 << 31) - 1
	min := 0 - (1 << 31)
	for _, c := range str {
		if c == '-' || c == '+' || c == ' ' {
			if symboled || numbered {
				break
			}
			if c != ' ' {
				symboled = true
			}
			if c == '-' {
				positive = false
			}
		} else if c >= '0' && c <= '9' {
			numbered = true
			num := int(c - '0')
			if positive {
				if sum != 0 {
					sum = sum*10 + num
				} else {
					sum = num
				}
				if sum > max {
					return max
				}
			} else {
				if sum != 0 {
					sum = sum*10 - num
				} else {
					sum = 0 - num
				}
				if sum < min {
					return min
				}
			}
		} else {
			break
		}
	}
	return sum
}
```