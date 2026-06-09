

```
func mySqrt(x int) int {
    if x == 0 {
        return 0
    }
    if x <= 3 {
        return 1
    }

    var l, r, m int64
    
    l = 0
    r = int64(x/2)
    
    for l <= r {
        m = (l+r)/2
        if m * m == int64(x) {
            return int(m)
        } else if m * m < int64(x) {
            l = m+1
        } else {
            r = m-1
        }
    }
    return int(r)
}
```