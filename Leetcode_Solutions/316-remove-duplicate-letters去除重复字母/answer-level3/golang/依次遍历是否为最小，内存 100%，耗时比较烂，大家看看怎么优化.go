### 解题思路

依次找最小的进行拼接到结果串

### 代码

```golang
func removeDuplicateLetters(s string) string {
    res := ""
    for k:=0; k<len(s); k++ {
        s0 := s[k]
        if strings.Contains(res, string(s0)) {
            continue
        }

        hasSmall := false
        hasRepeated := false
        for i:=k+1; i<len(s); i++ {
            if strings.Contains(res, string(s[i])) {
                continue
            } 
            if s[i] < s0 {
                hasSmall = true
            } else if s[i] == s0 {
                hasRepeated = true
                if hasSmall {
                    break
                }
            } else if i<len(s)-1 {
                for j:=i+1; j<len(s); j++ {
                    if s[j] == s0 {
                        hasRepeated = true
                        break
                    }
                }
                if !hasRepeated {
                    break
                }

                hasRep := false
                for j:=i+1; j<len(s); j++ {
                    if s[j] == s[i] {
                        hasRep = true
                        break
                    }
                }
                if !hasRep && !hasSmall {
                    hasRepeated = false
                    break
                }
            }
        }

        if !hasRepeated || !hasSmall {
            res += string(s0)
        }
    }
    return res
}
```