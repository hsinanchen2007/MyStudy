### 解题思路

当n对3取余若有余数，则返回false，无余数时，说明为3的倍数，便除以3，循环执行，若最后的n得1,则返回true

### 代码

```golang
func isPowerOfThree(n int) bool {
    if n == 0 {
        return false
    }
    for n != 1 {
        if n % 3 == 0 {
            n /= 3
        }else {
            return false
        }
    }
    return true
}
```