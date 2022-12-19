### 解题思路
限制环境位数一堆人拿 int_max 和结果比较然后输出是什么鬼。要是真有限制溢出后比较不可能是正确的啊。

### 代码

```golang
var charNumMap = map[rune]int{
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    '0': 0,
}
const int32Max = 1 << 31 -1
const int32Min = -1 << 31

func myAtoi(str string) int {
    ret := 0
    sign := 1
    isNumOnly := false
    for _, char := range str {
        if v, ok := charNumMap[char]; ok {
            negativeBound := int32Min
            if sign > 0 {
                negativeBound++
            }
            if negativeBound / 10 > -ret  {
                ret = -negativeBound
                break
            }
            ret *= 10
            if negativeBound + v > -ret {
                ret = -negativeBound
                break
            }
            ret += v
            isNumOnly = true
            continue
        }
        if isNumOnly {
            break
        }
        if char == ' ' {
            continue
        }
        if char == '-' {
            sign = -1
            isNumOnly = true
            continue
        }
        if char == '+'{
            isNumOnly = true
            continue
        }
        break
    }
    return ret * sign

}
```