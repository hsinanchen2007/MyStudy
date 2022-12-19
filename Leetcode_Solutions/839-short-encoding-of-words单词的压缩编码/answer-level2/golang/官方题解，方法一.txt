### 解题思路
此处撰写解题思路

### 代码

```golang
func minimumLengthEncoding(words []string) int {
    size := len(words)

    res := make([]string, 0)

    for i := 0; i < size; i++ {
        find := false
        for j := 0; j < len(res); j++ {
            a, b := len(words[i]), len(res[j])
            if a >= b {
                if res[j] == words[i][a - b : ] {
                    res[j] = words[i]
                    find = true
                    break
                }
            } else {
                if words[i] == res[j][b - a : ] {
                    find = true
                    break
                }
            }
        }
        if !find {
            res = append(res, words[i])
        }
    }

    length := 0
    for i := 0; i < len(res); i++ {
        length = length + len(res[i]) + 1
    }
    return length
}
```