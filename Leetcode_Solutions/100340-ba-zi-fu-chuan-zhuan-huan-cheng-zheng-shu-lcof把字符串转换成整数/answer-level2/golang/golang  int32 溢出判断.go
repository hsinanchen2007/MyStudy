### 解题思路
关键是 Int32 溢出判断

### 代码

```golang
func strToInt(str string) int {
    symbol := ' ' // symbol 正负号
    var arr []rune
    for _, m := range str {
        if m >= '0' && m <= '9' {// 数字部分，放到数组中
            arr = append(arr, m)
        }else {// 符号部分
            if len(arr) > 0 {// 数组长度大于 0，说明已到数字结尾，跳出循环
                break
            }else {// 未到数字部分
                if m != ' ' && m != '+' && m != '-' {// 不是加、减号、空格，则返回 0
                    return 0
                }else {// -，+，空格
                    if symbol != ' '{// -，+ 后应该是数字
                        return 0
                    }
                    symbol = m
                }
            }
        }
    }
    res := 0
    for i := 0; i < len(arr); i++ {
        ch := arr[i] - '0'
        if res > 214748364 || res == 214748364 && ch > 7 {// 关键步骤： int32 溢出判断
            if symbol == '-' {
                return -2147483648
            }else {
                return 2147483647
            }
        }
        res = res * 10 + int(ch)
    }  
    if symbol == '-' {
        return  -res
    }
    return res
}
```