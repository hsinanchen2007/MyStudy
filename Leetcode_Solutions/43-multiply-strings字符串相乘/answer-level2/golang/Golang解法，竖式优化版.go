### 解题思路
执行用时 :
4 ms, 在所有 Go 提交中击败了69.21%的用户

内存消耗 :
3 MB, 在所有 Go 提交中击败了72.00%的用户

### 代码

```golang
func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
        return "0"
    }
    digits := make([]int, len(num1)+len(num2))
    for i := len(num1)-1; i >= 0; i-- {
        for j := len(num2)-1; j >= 0; j-- {
            digit1, _ := strconv.Atoi(string(num1[i]))
            digit2, _ := strconv.Atoi(string(num2[j]))
            sum := digits[i+j+1] + digit1 * digit2
            digits[i+j+1] = sum % 10
            digits[i+j] += sum / 10
        }
    }
    result := ""
    isLeading := true
    for _, d := range digits {
        if isLeading {
            if d == 0 {
                continue
            } 
            isLeading = false
        }
        result = result + strconv.Itoa(d)
    }
    return result
}
```

###复杂度分析

时间复杂度：O(M * N)

空间复杂度：O(M + N)