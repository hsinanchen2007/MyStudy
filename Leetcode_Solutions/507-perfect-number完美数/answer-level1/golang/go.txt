### 解题思路
此处撰写解题思路

### 代码

```golang
func checkPerfectNumber(num int) bool {
    if num == 1 {
        return false
    }
    
    sum := 1 
    s := int(math.Sqrt(float64(num)))
    
    for i := 2; i <= s; i++ {
        if num % i == 0 {
            sum += i + (num / i)
        }
    }
    
    return sum == num
}
```