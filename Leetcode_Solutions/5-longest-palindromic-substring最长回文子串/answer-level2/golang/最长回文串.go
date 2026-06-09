### 解题思路
从一个pos开始， 向两侧移动指针。 注意奇数偶数的方式。

### 代码

```golang

// babad
// dabab
// aacdefcaa
// aacfedcaa
// List[i, j] 表示str1的第i个字符和str2的第j个字符相等的连续次数
// List[i, j] = List[i - 1, j - 1] + 1; str1[i] == str[j]
// List[i, j] = 0; str[i] != str[j]
func longestPalindrome(s string) string {
    if s == "" {
        return ""
    }
    var maxLen, dstPos int
    for i := 0; i < len(s); i++ {
        len := getPalindrome(s, i)
        if len > maxLen {
            maxLen = len
            dstPos = i
        }
    }
    if maxLen % 2 == 1 {
        return s[dstPos - maxLen / 2 : dstPos + 1 + maxLen / 2]
    }
    return s[dstPos - maxLen / 2 + 1 : dstPos + 1 + maxLen / 2]
}
func getPalindrome(s string, pos int) int {
    var i, j int
    i = pos - 1 
    j = pos + 1
    var result1 int = 1 
    var result2 int = 0
    for i >= 0 && j < len(s) {
        if s[i] == s[j] {
            result1 += 2
        } else {
            break
        }
        i--
        j++
    }
    i = pos
    j = pos + 1
    for i >= 0 && j < len(s) {
        if s[i] == s[j] {
            result2 += 2
        } else {
            break
        }
        i--
        j++
    }
    if result1 > result2 {
        return result1
    } 
    return result2
}

// func longestPalindrome(s1 string) string {
//     s2 := reverseString(s1)
//     var list [][]int = make([][]int, len(s1) + 1)
//     for i := 0; i < len(s1) + 1; i++ {
//         list[i] = make([]int, len(s1) + 1)
//     }
//     var max int
//     var posi int
//     for i := 1; i <= len(s1); i ++ {
//         for j := 1; j <= len(s2); j++ {
//             if s1[i - 1] == s2[j - 1] {
//                 list[i][j] = list[i - 1][j - 1] + 1
//                 if list[i][j] > max {
//                     max = list[i][j]
//                     posi = i
//                 }
//             }
//         }
//     }
//     var result string
//     result = s1[posi - max:posi]
//     fmt.Println(max, result)
//     return result
// }

// func reverseString(s string) string {
//     var result string
//     for i := len(s) - 1; i >= 0; i-- {
//         result += string(s[i])
//     }
//     return result
// }
```