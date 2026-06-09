### 解题思路
此处撰写解题思路

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
    if x+y < z {
        return false
    }
    if x == 0 || y == 0 {
        return z == 0 || x+y == z
    }
    return z % gcd(x,y) == 0
}

func gcd(i,j int) int{
    if i > j {
        i,j = j,i
    }
    if i == 1 {
        return 1
    }
    y := j % i
    if y == 0 {
        return i
    }
    return gcd(i,y)
}
```