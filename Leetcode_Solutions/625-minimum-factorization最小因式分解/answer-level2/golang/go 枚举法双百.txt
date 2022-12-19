### 解题思路
实际上就是看小于10的质数因子，而能组成的就只有2、3、4、5、6、7、8、9，枚举法。

### 代码

```golang
import "fmt"
import "math"
func smallestFactorization(a int) int {
    if a == 1 {
        return 1
    }
    factors := []int{}
    for a != 1 {
        for i := 2; i < 10; i++ {
            if a % i == 0 {
                a = a / i
                factors = append(factors, i)
                break
            }
            if i > 8 {
                return 0
            }
        }
    }
    if len(factors) == 0 {
        return 0
    }
    // 9 8 7 5 6 4 2
    countFactors := map[int]int{}
    res := 0
    level := 0
    for _, v := range factors {
        if v > 10 {
            return 0
        }
        if _, ok := countFactors[v]; !ok {
            countFactors[v] = 1
        } else {
            countFactors[v]++
        }
    }
    
    for len(countFactors) > 0 {
        // 9
        if _, ok := countFactors[3]; ok {
            if countFactors[3] >= 2 {
                countFactors[3] -= 2
                res += int(math.Pow10(level))*9
                level++
                if countFactors[3] == 0 {
                    delete(countFactors, 3)
                }
                continue
            }
        }
        // 8
        if _, ok := countFactors[2]; ok {
            if countFactors[2] >= 3 {
                countFactors[2] -= 3
                res += int(math.Pow10(level))*8
                level++
                if countFactors[2] == 0 {
                    delete(countFactors, 2)
                }
                continue
            }
        }
        // 7
        if _, ok := countFactors[7]; ok {
            countFactors[7]--
            res += int(math.Pow10(level))*7
            level++
            if countFactors[7] == 0 {
                delete(countFactors, 7)
            }
            continue
        }
        // 6
        if _, ok := countFactors[3]; ok {
            if _, ok := countFactors[2]; ok {
                countFactors[3]--
                countFactors[2]--
                res += int(math.Pow10(level))*6
                level++
                if countFactors[3] == 0 {
                    delete(countFactors, 3)
                }
                if countFactors[2] == 0 {
                    delete(countFactors, 2)
                }
                continue
            }
        }
        // 5
        if _, ok := countFactors[5]; ok {
            countFactors[5]--
            res += int(math.Pow10(level))*5
            level++
            if countFactors[5] == 0 {
                delete(countFactors, 5)
            }
            continue
        }
        // 4
        if _, ok := countFactors[2]; ok {
            if countFactors[2] >= 2 {
                countFactors[2] -= 2
                res += int(math.Pow10(level))*4
                level++
                if countFactors[2] == 0 {
                    delete(countFactors, 2)
                }
                continue
            }
        }
        // 3
        if _, ok := countFactors[3]; ok {
            countFactors[3]--
            res += int(math.Pow10(level))*3
            level++
            if countFactors[3] == 0 {
                delete(countFactors, 3)
            }
            continue
        }
        // 2
        if _, ok := countFactors[2]; ok {
            countFactors[2]--
            res += int(math.Pow10(level))*2
            level++
            if countFactors[2] == 0 {
                delete(countFactors, 2)
            }
            continue
        }
    }
    if res > (1<<31) {
        return 0
    }
    //fmt.Println(factors, len(countFactors))
    return res
}
```