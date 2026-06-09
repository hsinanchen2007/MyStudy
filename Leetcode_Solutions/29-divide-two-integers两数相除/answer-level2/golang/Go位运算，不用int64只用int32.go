不仅要考虑**输出时不溢出**，同时还要考虑**过程中任意时刻不溢出**。

```go
func divide(dividend int, divisor int) (result int) {
    // 是否异号
    sign := dividend ^ divisor

    // 边界溢出检查
    if dividend == minInt {
        if divisor >= 0 {
            dividend += divisor
            defer func() { result -= 1 }()
        } else {
            dividend -= divisor
            defer func() {
                if result!=maxInt{
                    result += 1
                }
            }()
        }
    }
    if divisor == minInt {
        return 0
    }

    // 都转换为正数
    dividend = (dividend ^ (dividend >> 31)) - (dividend >> 31)
    divisor = (divisor ^ (divisor >> 31)) - (divisor >> 31)

    // 找出结果的位数，防止左移溢出
    var dig uint
    for dig = 1; dividend >= divisor<<dig; dig++ {
        if divisor>>(30-dig) != 0 {
            dig++
            break
        }
    }
    // 开始计算
    for i := dig - 1; i > 0; i-- {
        if dividend >= divisor<<i {
            dividend -= divisor << i
            result |= 1 << i
        }
    }
    if dividend >= divisor {
        result |= 1
    }
    // 最后的正负处理
    if sign >= 0 {
        return result
    }
    return ^result +1
}

const maxInt = 1<<31 - 1
const minInt = -1 << 31
```
