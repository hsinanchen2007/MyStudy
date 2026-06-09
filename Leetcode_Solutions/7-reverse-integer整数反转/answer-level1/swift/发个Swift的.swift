```
func reverse(_ x: Int) -> Int {
        var result = 0
        var origin = x

        while origin != 0 {
            result = result * 10 + origin % 10
            origin = origin / 10
            
            if result > 2147483647 || result < -2147483648 {
                // 范围: [−2^31,  2^31 − 1],超出则返回0
                result = 0
            }
        }
        
        return result
        
    }
```
