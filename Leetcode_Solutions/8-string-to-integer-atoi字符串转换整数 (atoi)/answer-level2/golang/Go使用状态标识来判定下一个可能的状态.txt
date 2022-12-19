### 解题思路
使用当前状态标识来判定下一个状态

### 代码

```golang
func myAtoi(str string) int {
    const INT_MAX = int64(^uint32(0) >> 1)
    const INT_MIN = int64(-(1 << 31))
    // 状态: 0 - 起始字符判定, 1 - 符号位, 2 - 数字, 3 - 结束字符
    curState := 0
    sign := 1
    var ans int64
    for _, c := range str {
        switch curState {
        case 0:
            if c == ' ' {
                continue
            } else if c == '-' || c == '+' {
                curState = 1
                if c == '-' {
                    sign = -1
                }
            } else if c >= '0' && c <= '9' {
                curState = 2
                ans = int64(c - '0')
            } else {
                return 0
            }
        case 1:
            if c >= '0' && c <= '9' {
                curState = 2
                ans = int64(sign * int(c - '0'))
            } else {
                return 0
            }
        case 2:
            if c >= '0' && c <= '9' {
                ans = 10 * ans + int64(sign * int(c - '0'))
                if ans > INT_MAX {
                    return int(INT_MAX)
                } else if ans < INT_MIN {
                    return int(INT_MIN)
                }
            } else {
                return int(ans)
            }
        }
    }
    return int(ans)
}
```