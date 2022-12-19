使用26长度的repo数组存储所有big中字母的坐标，扫描模式串数组，通过首字母定位repo数组，以此来知道big中有没有这个字母，如果有那就比较子串，可以先把big哈希出来，然后在遍历每个子串也把子串哈希了，比较相等就是O(1)的而不是O(N)。
```
func multiSearch(big string, smalls []string) [][]int {
    n := len(smalls)
    if n == 0 {
        return nil
    }
    tn := len(big)
    h, p, P := make([]uint64, tn+1), make([]uint64, tn+1), uint64(131)
    var repo[26][]int
    p[0] = 1
    for i := 1; i <= tn; i++ {
        c := big[i-1]-'a'
        repo[int(c)] = append(repo[int(c)], i-1)
        h[i] = h[i-1]*P + uint64(c) + 1
        p[i] = p[i-1]*P
    }
    res := make([][]int, n)
    for i := 0; i < n; i++ {
        if smalls[i] == "" {
            continue
        }
        if pos := repo[int(smalls[i][0]-'a')]; len(pos) > 0 {
            hash := uint64(0)
            slen := len(smalls[i])
            for j := 1; j <= slen; j++ {
                hash = hash*P + uint64(smalls[i][j-1]-'a') + 1
            }
            for j := 0; j < len(pos); j++ {
                if pos[j]+slen <= tn && hash == h[pos[j]+slen]-h[pos[j]]*p[slen] {
                    res[i] = append(res[i], pos[j])
                }
            }
        }
    }
    return res
}
```
