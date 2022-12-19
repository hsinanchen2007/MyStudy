### 解题思路
1.将数字的每一位放到int slice中
2.遍历slice的前一半，比较每一位与其对称位的值是否相对

### 代码

```golang
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	if x > 0 && x % 10 == 0 {
		return false
	}
	var nums []int
	for x > 0 {
		y := x % 10
		nums = append(nums,y)
		x /= 10
	}
	l := len(nums)
	var halfLen int
	//只遍历slice的一半即可
	if l% 2 == 0{
		halfLen = l /2
	}else {
		halfLen = (l-1) /2
	}
	var isPalindrome bool = true
	for i,v := range nums {
		if i == halfLen {
			break
		}
		if v != nums[l-i-1] {
			isPalindrome = false
			break
		}
	}
	return isPalindrome
}

```