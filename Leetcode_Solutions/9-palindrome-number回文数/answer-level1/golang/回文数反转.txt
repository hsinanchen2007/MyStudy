### 解题思路

首先判断边界：
1. 小于0的不是的;
1. 满足以上条件如果数字只有一位，则是;
1. 满足以上两个条件后，最低位(个位)为0不是的;
再次进行数字反转一半，如果反转后的数字与剩下的数字相等，或者反转数字去掉最后一位与剩下的数字相等，则是
反转一半的边界条件为，剩下的数值<反转数字时

### 代码

```golang
func isPalindrome(x int) bool {
	if x < 0 || (x%10) == 0 {
        if x >=  0&& x/10 == 0 {
            return true
        }
		return false
	}
    
	rev := 0
	for x > rev {
		y := x % 10
		x /= 10
		rev = y + rev*10
	}
	if x == rev {
		return true
	}
	return (rev / 10) == x
}
```