### 解题思路
此处撰写解题思路

### 代码

```golang
func plusOne(digits []int) []int {
	digits[len(digits)-1] = digits[len(digits)-1]+1
	for i:=len(digits)-1;i>0;i--{
		if digits[i]>9{
			digits[i-1] = digits[i-1]+1
			digits[i] = 0
		}
	}
	if digits[0]>9{
		digits[0] = 0
		newdigits := append([]int{1},digits...) 
		return newdigits
	}
	return digits
}
```