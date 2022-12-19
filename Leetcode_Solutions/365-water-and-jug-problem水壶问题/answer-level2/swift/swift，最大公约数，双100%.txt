思想：求x与y的最大公约数，能否被z整除

```
    func canMeasureWater(_ x: Int, _ y: Int, _ z: Int) -> Bool {
        if x + y < z {
            return false
        }
        if x == 0 || y == 0 {
            return z == 0 || x + y == z
        }
        return z % gcd(a: x, b: y) == 0
    }
    
    func gcd(a: Int, b: Int) -> Int {
        return b > 0 ? gcd(a: b, b: a % b) : a
    }
```
