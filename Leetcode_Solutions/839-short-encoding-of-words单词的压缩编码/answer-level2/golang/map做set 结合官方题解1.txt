map做set 结合官方题解1
```
func minimumLengthEncoding(words []string) int {
    m := make(map[string]bool)
    for i := range words{
        m[words[i]] = true
    }

    for w := range m{
        for i := 1; i < len(w) - 1;i++{
            if m[w[i:]] {
                delete(m, w[i:])
            }
        }
    }

    count := 0
    for w := range m{
        count += len(w) + 1
    }

    return count 
}
```

