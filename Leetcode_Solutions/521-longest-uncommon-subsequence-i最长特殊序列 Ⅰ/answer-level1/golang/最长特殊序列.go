理了半天题目，原来是这意思

```
func findLUSlength(a string, b string) int {
    if a == b {
        return -1
    }
    b1 := strings.Contains(a, b)
    if b1 {
        return len(a)
    }

    b2 := strings.Contains(b, a)
    if b2 { 
        return len(b)
    }
    if len(a) > len(b) {
        return len(a)
    }
    return len(b)
}
```
