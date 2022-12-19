### 解题思路
此处撰写解题思路

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
    if x == 0 || y == 0 {
        if z == 0 {
            return true
        } else {
            if x > 0 {
                return z % x == 0
            } else if y > 0{
                return z % y == 0
            } else {
                return false
            }
        }
    }
    if x + y < z {
        return false
    } else {
        return z % gcd(x, y) == 0
    }
}

func gcd(x, y int) int {
    if x % y == 0 {
        return y
    } else {
        return gcd(y, x % y)
    }
}
```