等差数列前 n 项和:Sn = n * (a1+an) / 2
减去输入数组，最后结果就是缺失的值

```
func missingNumber(nums []int) int {
    n := len(nums)
    sum := (n+1) * n/2
    for _, num := range(nums){
        sum -=  num
    }
    return sum
} 
```
