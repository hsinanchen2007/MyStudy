思路就是用小容器迭代的往大容器里倒水，直到产生合适的解。
```
func getMaxMin(x int, y int) (int, int) {
    if y > x {
        x, y = y, x
    }
    return x, y
}
func canMeasureWater(x int, y int, z int) bool {
    // 1. z > x + y => 不存在
    if z > x + y {
        return false
    }
    // 2. z == x + y => x + y = z
    if z == x + y {
        return true
    }
    // 3. z < x + y
    max, min := getMaxMin(x, y)
    if min == 0 || max == 0 {
        if max == z || min == z{
            return true
        } else {
            return false
        }
    }

    cnt := min
    tmp := 0
    for i := 0; i < cnt;  {
        if min + tmp == z || tmp == z || min == z {
            return true
        } else {
            tmp += min
            if tmp > max {
                tmp -= max
                i++
            }
        }
    }

    return false
}
```
