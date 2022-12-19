```
func respace(dictionary []string, sentence string) int {
    n := len(sentence)
    if n == 0 {
        return 0
    }
    h, p, P := make([]uint64, n+1), make([]uint64, n+1), uint64(131)
    p[0] = 1
    for i := 1; i <= n; i++ {
        h[i] = h[i-1]*P + uint64(sentence[i-1]-'a') + 1
        p[i] = p[i-1]*P
    }
    dict := make(map[uint64]bool, len(dictionary))
    for i := 0; i < len(dictionary); i++ {
        s := dictionary[i]
        hash := uint64(0)
        for j := 0; j < len(s); j++ {
            hash = hash*P + uint64(s[j]-'a') + 1
        }
        dict[hash] = true
    }
    f := make([]int, n+1)
    for i := 1; i <= n; i++ {
        f[i] = 1<<31 - 1
    }
    for i := 1; i <= n; i++ {
        for j := 1; j <= i; j++ {
            if dict[h[i]-h[j-1]*p[i-j+1]] {
                f[i] = min(f[i], f[j-1])
            }
        }
        f[i] = min(f[i], f[i-1]+1)
    }
    return f[n]
}
func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}
```
