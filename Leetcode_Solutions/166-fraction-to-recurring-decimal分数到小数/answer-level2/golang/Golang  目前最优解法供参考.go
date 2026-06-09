![屏幕快照 2019-11-17 21.50.28.png](https://pic.leetcode-cn.com/fc34c823bd3bc43b8377a5e55dc0252526e4a2e380e5d343ee537479019cf9e6-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-17%2021.50.28.png)
1、先判断分子和分母为0的特殊情况
2、判断返回值的符号，若为正数，不用处理；若为负数，则先添加一个“-”号至结果中
3、将分子和分母的转换为绝对值（去掉符号的影响）
4、先计算整数的部分
5、for循环处理小数部分
5.1 当出现小数部分余数为0时，可以退出for循环
5.2 当出现循环余数（即，该余数已经出现过一次），也可以退出for循环
6、对于出现小数循环的情况，在结果中，额外添加"()"
```
func fractionToDecimal(numerator int, denominator int) string {
    if numerator == 0 {
        return "0"
    }
    if denominator == 0 {
        return "NaN"
    }
    var buffer bytes.Buffer
    if (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) {
        buffer.WriteString("-")
    }

    num := int(math.Abs(float64(numerator)))
    denom := int(math.Abs(float64(denominator)))

    buffer.WriteString(strconv.Itoa(num/denom))
    num = num%denom
    if num == 0{
        return buffer.String()
    }

    buffer.WriteString(".")

    m := make(map[int]int, 10)
    repeatPos := -1
    for {
        num *= 10
        pos, ok := m[num]    
        if false == ok {
            m[num] = buffer.Len()
        }else{
            repeatPos = pos
            break
        }
        buffer.WriteString(strconv.Itoa(num/denom))
        //fmt.Println(buffer, len(buffer), num)
        num %= denom
        if num == 0 {
            break
        }
    }

    if repeatPos == -1{
        return buffer.String()
    }
    res := buffer.String()
    return fmt.Sprintf("%s(%s)", res[0:repeatPos], res[repeatPos:])
}
```
