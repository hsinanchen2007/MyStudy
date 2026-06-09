**解题思路**
声明两个变量分别记录x和y的累积数，判断和是否小于bound，是则加入map，然后从map中遍历结果到slice中
特别注意的是：要处理x和y为1的情景，否则进入死循环。

```
func powerfulIntegers(x int, y int, bound int) []int {
    var ans []int
    m := make(map[int]bool)
    powerX, powerY := 1, 1

    for powerX < bound {
        for powerY < bound {
            t := powerX + powerY
            if t <= bound {
                m[t] = true
            }
            powerY *= y
            if powerY == 1 {
                break
            }
        }

        powerX *= x
        powerY = 1
        if powerX == 1 {
            break
        }
    }

    for k, _ := range m {
        ans = append(ans, k)
    }
    return ans
}
```
