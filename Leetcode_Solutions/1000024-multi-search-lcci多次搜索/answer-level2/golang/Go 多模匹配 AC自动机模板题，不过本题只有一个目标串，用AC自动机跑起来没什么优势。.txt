使用Trie图来表示自动机
```
func multiSearch(big string, smalls []string) [][]int {
    n := len(smalls)
    if n == 0 {
        return nil
    }
    trie := make([][26]int, 100010)
    end := make([]int, 100010)
    next := make([]int, 100010)
    idx := 0
    insert := func(s string, k int) {
        p := 0
        for i := 0; i < len(s); i++ {
            c := int(s[i]-'a')
            if trie[p][c] == 0 {
                idx++
                trie[p][c] = idx
            }
            p = trie[p][c]
        }
        end[p] = k
    }
    build := func() {
        var q []int
        for i := 0; i < 26; i++ {
            if trie[0][i] != 0 {
                q = append(q, trie[0][i])
            }
        }
        for len(q) > 0 {
           nlen := len(q)
           for i := 0; i < nlen; i++ {
               t := q[i]
               for j := 0; j < 26; j++ {
                   c := &trie[t][j]
                   if *c == 0 {
                       *c = trie[next[t]][j]
                   } else {
                       next[*c] = trie[next[t]][j]
                       q = append(q, *c)
                   }
               }
           }
           q = q[nlen:]
        }
    }
    for i := 0; i < n; i++ {
        insert(smalls[i], i+1)
    }
    build()
    res := make([][]int, n)
    search := func(s string) {
        p := 0
        for i := 0; i < len(s); i++ {
            c := int(s[i]-'a')
            j := trie[p][c]
            for j > 0 {
                if end[j] > 0 {
                    res[end[j]-1] = append(res[end[j]-1], i-len(smalls[end[j]-1])+1)
                }
                j = next[j]
            }
            p = trie[p][c]
        }
    }
    search(big)
    return res
}
```
