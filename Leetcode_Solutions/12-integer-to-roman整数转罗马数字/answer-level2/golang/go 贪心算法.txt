```
func intToRoman(num int) string {
	/**
	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
	*/
	nums := []int{1000,900,500,400,100,90,50,40,10,9,5,4,1}
	ss := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	i := 0
	var buffer bytes.Buffer
	for num > 0 && i < len(nums){
		if num >= nums[i]{
			buffer.WriteString(ss[i])
			num = num-nums[i]
		}else {
			i++
		}
	}
	return buffer.String()
}
```
