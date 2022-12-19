分批循环填充，高效。

例如，对于 "29"，会有 3 * 4 = 12 个字符串。分批填充：
- 2 对应 "abc"，now = 12 / 3 = 4，每 4 个填充同一个字符，循环到底
- 9 对应 "wxyz"，now = 4 / 4 = 1，每 1 个填充同一个字符，循环到底
```go
func letterCombinations(digits string) []string {
    if len(digits) < 1 {
        return make([]string, 0)
    }
    m := map[byte] string {
        '2': "abc", '3': "def", '4': "ghi",
        '5': "jkl", '6': "mno", '7': "pqrs",
        '8': "tuv", '9': "wxyz",
    }
    // 计算结果个数，并创建字符串数组
    count := 1
    for i := range digits {
        count *= len(m[digits[i]])
    }
    ret := make([]string, count)
    // 遍历每个数字，根据当前数字对应的字符个数分批循环，逐个填充
    now := 1
    for i := range digits {
        now *= len(m[digits[i]])
        for j := range ret {
            idx := j / (count / now)
            for idx > len(m[digits[i]]) - 1 {
                idx %= len(m[digits[i]])
            }
            ret[j] += string(m[digits[i]][idx])
        }
    }
    return ret
}
```