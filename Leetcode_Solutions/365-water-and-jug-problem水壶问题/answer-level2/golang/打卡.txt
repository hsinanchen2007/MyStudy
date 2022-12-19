### 解题思路
数学

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
    if x==0 && y==0 {
        return z==0
    }

    if z > x + y {
        return false
    }

    a := 0
    if y==0 {
        a = gcd(y,x)
    } else {
        a = gcd(x,y)
    }

    return z%a == 0
}

func gcd(a,b int) int {
    if a%b ==0 {
        return b
    }
    return gcd(b,a%b)
}

```