```
func isHappy(n int) bool {
    s := n 
    for n > 1 {
        s = 0
        for n > 0 {
            s += (n%10)*(n%10)
            n /= 10
        }
        if s == 1 {
            return true
        } else if s == 4 {
            return false
        }
        n = s
    }
    
    return true 
}
```


//  4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 