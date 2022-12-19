
![image.png](https://pic.leetcode-cn.com/30adc2616f77d773e9e02a75909bb99cd7640be4c0d80471835499c5c78e452c-image.png)


```
func addDigits(num int) int {
    for num>9 {
        sum := 0
        for num!=0 {
            sum += num%10
            num /= 10
        }
        num = sum
    }
    return num
}
```