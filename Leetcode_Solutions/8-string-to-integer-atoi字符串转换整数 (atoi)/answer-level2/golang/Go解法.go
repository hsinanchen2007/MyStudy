第一次写结题 写得不好请见谅
解题思路：Loop 检查看当前的字符是不是数字，Loop的时候有几个需要注意的地方
- 字符不是数字
    - 是不是空格？（
    - 用没有出现过数字？（出现过数字就不用Loop了）
    - 是不是加减符号？（如果已经出现了加减符号)
    - 加减号和空格以外 （return 0 或者当前总值）
- 是数字
    - 总数值乘以10加上当前数值
    - 总数值有没有大于32位的最大（小）值？（有的话可以直接return最大/小值了）
```
func myAtoi(str string) int {
    num := 0
    // 是不是负数， 数字有没有出现过， 有没有见过空格以外的字符
    neg, digit, see := false, false, false
    for _, char := range str {
        // 检查是不是数字 - 如果不是数字的话
        if (char > '9') || (char < '0') {
            // 如果出现过数字 或者负号 或者 没见过数字但见过空格以外的字符
            if (digit || (neg && (char == '-')) || (!digit && see)) {
                break
            } else if (char == '-') || (char == '+') {
                // 检查是不是加减符号
                if char == '-' {
                    neg = !neg
                }
            } else {
                // 其余的字符abcd空格..等
                // 如果字符是空格然后也没有出现 “  42” 跳到下个字符
                if (char == ' ' && !digit) {
                    continue
                } else if (char == ' ' && digit) {
                    // 当前字符是空格，如果已经有数字出现过了 “4 2” -> 4
                    break;
                } else if (char != ' ' && !digit) {
                    // 如果当前字符不是空格 而且没有数字出现过 ”w42“
                    return 0
                }
                break;
            }
            // 如果见
            see = true
        } else {
            digit = true    //出现过数字了
            // 最后数值等于之前数值 * 10 + 当前数字
            num = num * 10 + int(char - '0')
            // 如果数值大于最大
            if (num > (1 << 31) - 1) {
                if neg {
                    return -1 << 31 
                }
                return (1 << 31) - 1
            }
        }
    }
    // 如果负数的话 最后答案乘以 -1
    if neg {
        num *= -1
    }
    return num
}
```
总而言之就是各种个样的case要检测，我提交的时候也忘了几个case。大家结题的时候多注意。