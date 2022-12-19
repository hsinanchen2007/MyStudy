### 解题思路
1. strip leading zeroes，获得strippedString
2. 判定正负，给sign赋值
3. for loop char in strippedString：判定是否为数字，是否超出极限值，符合条件的话result = result * 10 + sign * int(char - '0')
4. return result

### 代码

```golang
func myAtoi(str string) int {
    if len(str) == 0 {
        return 0
    }
    strippedStr := stripLeadingWhitespace(str)
    sign := 1
    result := 0
    for i, char := range strippedStr {
        if i == 0 {
            if char == '-' {
                sign = -1
            } else if char == '+' {
                sign = 1
            } else if int(char - '0') >= 0 && int(char - '0') <= 9 {
                result = result * 10 + int(char - '0')
            } else {
                return result
            }
        } else {
            if int(char - '0') < 0 || int(char - '9') > 9 {
                break
            }
            if sign == -1 && result * 10 + sign * int(char - '0') < math.MinInt32 {
                return math.MinInt32
            }
            if sign == 1 && result * 10 + int(char - '0') > math.MaxInt32 {
                return math.MaxInt32
            }
            result = result * 10 + sign * int(char - '0')
        }
    }
    return result
}

func stripLeadingWhitespace(str string) string {
    result := ""
    isLeading := true
    for _, char := range str {
        if isLeading {
            if char != ' ' {
                isLeading = false
                result = result + string(char)
            }
        } else {
            result = result + string(char)
        }
    }
    return result
}
```

### 复杂度分析
时间复杂度：O(n), 线性时间遍历string
空间复杂度：O(1), 常数空间存储临时变量