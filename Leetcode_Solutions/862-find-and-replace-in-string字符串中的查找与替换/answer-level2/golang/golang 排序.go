因为indexes是无序的，所以我们需要对indexes和对应的sources，targets排序。
排完序开始替换

具体替换见注释
```
func findReplaceString(S string, indexes []int, sources []string, targets []string) string {
    n := make([]Node, len(indexes))
    for i := 0; i < len(indexes); i++ {
        n[i] = Node{indexes[i], sources[i], targets[i]}
    }
    sort.Slice(n, func(i, j int) bool {
        return n[i].idx < n[j].idx
    })
    sIdx := 0 // S尚未替换的开始下标
    ret := make([]byte, 0, 100000)
    // 遍历node
    for i := 0; i < len(n); i++ {
        // 如果sIdx < n[i].idx ，说明sIdx不需要替换，直接append到返回值中。
        for sIdx < n[i].idx {
            ret = append(ret, S[sIdx])
            sIdx++
        }
        // 判断是否可以替换
        if n[i].idx+len(n[i].source) <= len(S) && S[n[i].idx:n[i].idx+len(n[i].source)] == n[i].source {
            ret = append(ret, []byte(n[i].target)...) // 替换
            sIdx = n[i].idx+len(n[i].source) // 下标变成替换字符串的下一个
        }
    }
    return string(ret) + S[sIdx:] //如果有还有没有被替换的，需要加上
}

type Node struct{
    idx int
    source string
    target string
}
```