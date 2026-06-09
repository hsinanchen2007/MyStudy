```
func isValid(s string) bool {
    if s == "" {
        return true
    } else if len(s) % 2 != 0 {
        return false
    } else {
        maps := map[byte]byte{
            '(':')', '[':']', '{':'}',
        }
        n := len(s)
        res := []byte{'a'}
        res = append(res, s[0])
        if res[1] != '(' && res[1] != '[' && res[1] != '{' {
            return false
        } else {
            for i := 1; i < n; i++ {
                l := len(res)
                if s[i] == maps[res[l-1]] {
                    res = res[:l-1]
                } else if s[i] == '(' || s[i] == '[' || s[i] == '{' {
                    res = append(res, s[i])
                } else {
                    return false
                }
            }
        }
        return len(res) == 1
    }
}
```
