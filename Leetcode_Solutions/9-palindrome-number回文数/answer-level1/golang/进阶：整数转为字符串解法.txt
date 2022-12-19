## 原题解法：
```golang
func isPalindrome(x int) bool {
    
    // 负数肯定不是回文，因为负号
    if x < 0 {
        return false
    }
    
    // 记录下原始数字
    originX := x
    
    // 反转数字
    rev := 0
    for x != 0 {
        pop := x % 10
        x /= 10
        rev = rev * 10 + pop
    }
    
    // 原始数字和反转数字对比
    if originX == rev {
        return true
    }
    return false
}
```



## 进阶：整数转为字符串解法：
```golang
import "strconv"
import "strings"

func isPalindrome(x int) bool {

	// 数字转换为字符串
	s := strconv.Itoa(x)

	// 字符串分割成字符串slice
	ss := strings.Split(s, "")
	slen := len(ss)

	// 第一个字符和最后一个对比，以此类推，只需要对比一半字符串即可
	for i := 0; i <= slen/2-1; i++ {
		if ss[i] != ss[slen-1-i] {
			return false
		}
	}

	return true
}
```
