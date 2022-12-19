```
func checkInclusion(s1 string, s2 string) bool {
    if len(s1) > len(s2) {
        return false
    }

    chars := make([]int, 26)

    for idx := range s1 {
        chars[s1[idx] - 'a'] += 1
    }

    i := 0

    s1l := len(s1)
    s2l := len(s2)

    for {
        j := i

        for {
            idx := s2[j] - 'a'
            if chars[idx] > 0 {
                chars[idx] -= 1
                
                if j - i + 1 == s1l {
                    return true
                }
                j += 1

                if j > s2l - 1 {
                    return false
                }
                continue
            } else {
                if i == s2l - 1 {
                    return false
                }
                if j > i {
                    chars[s2[i] - 'a'] += 1
                    i += 1
                    continue
                } else {
                    i = i + 1
                    break
                }
            }
        }
    }
}
```
