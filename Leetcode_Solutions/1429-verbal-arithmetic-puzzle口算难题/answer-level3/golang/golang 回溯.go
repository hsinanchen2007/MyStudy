从个位开始计算，更快的过滤掉没用的数据
```golang
func isSolvable(words []string, result string) bool {
    return isSolvableLevel(1, words, result, map[byte]int{}, map[int]bool{}, 0)
}

func isSolvableLevel(level int, words []string, result string, str2digit map[byte]int, used map[int]bool, add int) bool {
    m := map[byte]bool{}
    for i := 0; i < len(words); i++ {
        if len(words[i]) >= level {
            m[words[i][len(words[i]) - level]] = true
        }
    }
    vals := []byte{}
    for k := range m {
        if _, ok := str2digit[k]; ok {
            continue
        }
        vals = append(vals, k)
    }
    if len(result) < level {
        return len(m) == 0 && add == 0
    }
    r := result[len(result) - level]
    if !m[r] {
        if _, ok := str2digit[r]; !ok {
            vals = append(vals, r)
        } 
    }
    return backtrace(level, 0, vals, words, result, str2digit, used, add)
} 

func backtrace(level, idx int, vals []byte, words []string, result string, str2digit map[byte]int, used map[int]bool, add int) bool {
    if idx == len(vals) {
        left, right := 0, 0
        for i := 0; i < len(words); i++ {
            if len(words[i]) >= level {
                left += str2digit[words[i][len(words[i]) - level]]
            }
            if len(words[i]) == level && len(words) > 1 && str2digit[words[i][len(words[i]) - level]] == 0 {
                return false
            }
        }
        right = str2digit[result[len(result) - level]]
        if len(result) > 1 && len(result) == level && right == 0 {
            return false
        }
        if (left + add)%10 == right {
            return isSolvableLevel(level + 1, words, result, str2digit, used, (left + add)/10)
        }
        return false
    }
    for i := 0; i <= 9; i++ {
        if used[i] {
            continue
        }
        str2digit[vals[idx]] = i
        used[i] = true
        if backtrace(level, idx+1, vals, words, result, str2digit, used, add) {
            return true
        }
        used[i] = false
        delete(str2digit, vals[idx])
    }
    return false
}

```
