
![image.png](https://pic.leetcode-cn.com/a0309a0d2182a20b297615470641de36d4e5bebbb911086f4b40fd01af614303-image.png)


```
func isUgly(num int) bool {
    if num == 0 {
        return false
    }
    for num!=1 {
        if num%2==0 {
            num /= 2
        } else if num%3==0 {
            num /=3 
        } else if num%5==0 {
            num /=5
        } else {
            return false
        }   
    }
    return true
}
```