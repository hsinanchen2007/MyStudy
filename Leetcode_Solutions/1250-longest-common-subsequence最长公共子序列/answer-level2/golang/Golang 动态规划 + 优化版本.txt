```
func longestCommonSubsequence(text1 string, text2 string) int {
    // dp
    // d[i][j] 长度分别为i和j的字符串的最长公共子序列长度
    if text1 == text2 {
        return len(text1)
    }

    // 1 dp
    // d := make([][]int, len(text1) + 1)
    // for i := 0; i <= len(text1); i++ {
    //     d[i] = make([]int, len(text2) + 1)
    //     d[i][0] = 0
    // }

    // for j := 0; j <= len(text2); j++ {
    //     d[0][j] = 0
    // }

    // for i := 1; i <= len(text1); i++ {
    //     for j := 1; j <= len(text2); j++ {
    //         if text1[i - 1] == text2[j - 1] {
    //             d[i][j] = d[i-1][j-1] + 1
    //         } else {
    //             d[i][j] = maxInt(d[i-1][j], d[i][j-1])
    //         }
    //     }
    // }
    // return d[len(text1)][len(text2)]
    
    // 2 优化后
    d := make([]int, len(text1) + 1)
    for j := 1; j <= len(text2); j++ {
        pre := d[0]
        for i := 1; i <= len(text1); i++ {
            tmp := d[i]
            if text1[i - 1] == text2[j - 1] {
                d[i] = pre + 1
            } else {
                d[i] = maxInt(d[i-1], d[i])
            }
            pre = tmp
        }
    }
    return d[len(text1)]
}

func maxInt(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```
