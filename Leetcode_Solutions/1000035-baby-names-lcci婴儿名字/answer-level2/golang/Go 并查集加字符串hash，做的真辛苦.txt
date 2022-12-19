```
func trulyMostPopular(names []string, synonyms []string) []string {
    n := len(names)
    h := make(map[string]uint64, n)
    repo := make(map[uint64]int, n)
    cnt := make([]int, n)
    p := make([]int, n)
    realName := make([]string, n)
    for i := range p {
        p[i] = i
    }
    for i := 0; i < n; i++ {
        s := names[i]
        b1, b2 := strings.IndexByte(s, '('), strings.IndexByte(s, ')')
        cnt[i], _ = strconv.Atoi(s[b1+1:b2])
        h[s[:b1]] = hash(s[:b1])
        repo[h[s[:b1]]] = i
        realName[i] = s[:b1]
    }
    var get func(u int) int
    get = func(u int) int {
        if p[u] != u {
            p[u] = get(p[u])
        }
        return p[u]
    }
    for i := 0; i < len(synonyms); i++ {
        s := synonyms[i][1:len(synonyms[i])-1]
        str := strings.Split(s, ",")
        s1, s2 := str[0], str[1]
        p1, p2 := get(repo[h[s1]]), get(repo[h[s2]])
        if p1 != p2 {
            if cmp(realName[p1],realName[p2]) {
                p[p1] = p2
                cnt[p2] += cnt[p1]
            } else {
                p[p2] = p1
                cnt[p1] += cnt[p2]
            }
        }
    }
    var res []string
    for i := 0; i < n; i++ {
        if p[i] == i {
            res = append(res, fmt.Sprintf("%s(%d)", realName[i], cnt[i]))
        }
    }
    return res
}
func hash(a string) uint64 {
    P := uint64(131)
    v := uint64(0)
    for i := 1; i <= len(a); i++ {
        v = v*P + uint64(a[i-1]-'A')+1
    }
    return v
}
func cmp(a, b string) bool {
    for i := 0; i < min(len(a), len(b)); i++ {
        if a[i] > b[i] {
            return true
        } else if a[i] < b[i] {
            return false
        }
    }
    return len(a) > len(b)
}
func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}

```
