### 解题思路
首先判断x的符号，x<0直接返回false，然后求x的逆序整数，返回两者的比较结果

### 代码

```golang
func isPalindrome(x int) bool {
    if x<0{
        return false
    }
    y:=0
    z := x
    for x!=0{
        y = y*10+x%10
        x /= 10
    }
    return y==z
}
```