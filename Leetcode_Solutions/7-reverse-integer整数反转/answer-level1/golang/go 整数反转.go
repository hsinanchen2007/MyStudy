```
const maxint = int(^uint32(0) >> 1)
const minint = ^maxint

func reverse(x int) int {
    
    if x > maxint || x < minint {
        return 0
    }
    
    var result, yu int
    for {
        yu = x % 10
        x /= 10
        
        result = result * 10 + yu
        
        if result > maxint || result < minint {
            return 0
        }
        
        if x == 0 {
            break
        }
    }
    
    return result
}
```

对负数取余的结果还是负数