### 解题思路
遍历所有数字统计1个数是否为质数

### 代码

```golang
func countPrimeSetBits(L int, R int) int {
    count := func(x int) int {
        c := 0
        for x > 0 {
            if x & 1 == 1 {
                c++
            }
            x = x>>1
        }
        return c
    }
    res := 0
    for i := L; i <= R; i++ {
        switch count(i) {
            case 2, 3, 5, 7, 11, 13, 17, 19:
                res++
            default:
                continue
        }
    }
    return res
}

```