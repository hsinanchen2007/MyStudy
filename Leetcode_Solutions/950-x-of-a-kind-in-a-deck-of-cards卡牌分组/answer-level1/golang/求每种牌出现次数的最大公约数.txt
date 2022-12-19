### 解题思路

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    cnts := make([]int, 10001)
    size := len(deck)
    for i := 0; i < size; i++ {
        cnts[deck[i]]++
    }
    GCD := 0
    for i := 0; i < 10001; i++ {
        if cnts[i] != 0 {
            if GCD == 0 {
                GCD = cnts[i]
                continue
            }
            temp := gcd(GCD, cnts[i])
            if temp > 1 {
                GCD = temp
            } else {
                return false
            }
        }
    }
    return GCD > 1
}

func gcd(x, y int) int {
    for x % y != 0 {
        x, y = y, x % y
    }
    return y
}
```