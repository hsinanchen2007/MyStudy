/**
66.加一算法
 */

/**
思路：
要考虑
每位都是9
每位不都为9
 */
func plusOne(digits []int) []int {
	length:=len(digits)-1
	i:=length-1
	for ;i>=0;i--{
		if digits[i] == 9 {
			digits[i] = 0
			continue
		}else{
			digits[i]+=1
			return digits
		}
	}
	if i==-1 {
		//每位都为9，最前面添加1
		length+=1
		digits = append(digits, 0)
		digits[0] = 1
	}
	return digits
}