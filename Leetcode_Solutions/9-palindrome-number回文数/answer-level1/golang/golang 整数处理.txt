### 解题思路
1. 之前写过回文字符串的判断是比较好做的，但是仔细想整数的特殊性就在于可以通过求余和商的形式来进行反转
2. 时间复杂度为o(n)

### 代码

```golang
func isPalindrome(x int) bool {
 if x<0{
  return false
 }
 if x<10{
  return true
 }
 tmp:=x
 reverse:=0
 for{
  if tmp==0{
   break
  }
  reverse=reverse*10+tmp%10
  tmp=tmp/10
 }
 println(reverse)
 if reverse==x{
  return true
 }else{
  return false
 }
}
```