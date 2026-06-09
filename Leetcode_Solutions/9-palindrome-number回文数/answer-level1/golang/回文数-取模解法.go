解题思路：
1.负数一律不是回文
2.数字是否超过int32位
3.将数字反转后匹配
```
func isPalindrome(x int) bool {
    if x < 0 { return false }  //负数一律返回false
    if x == 0 { return true } 
    if !(-(1<<31) <= x && x <= (1<<31)-1) { return false} //判断数字是否超过32位
    y := x //将x的值赋值给y，保持x的值不变
    z := 0
    //进行整数的反转
    for {
        if y == 0 { break }
        z = z*10 + y%10
        y /= 10
    }
    //反转后的数与原值匹配
    if x == z {
        return true
    } else {
        return false
    }
}
```
