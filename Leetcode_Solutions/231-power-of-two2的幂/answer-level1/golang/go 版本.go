```javascript []
func isPowerOfTwo(n int) bool {
    res := false
    for (n > 0) {
        if (n == 1){
            res = true
            break
        }
        if (n % 2 != 0) {
            res = false
            break
        }
        if (n % 2 == 0) {
            n = n/2
        } 
    }
    return res
}
```

