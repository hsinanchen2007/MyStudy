每次发奖的时候，把这个人获得的leetcoin同时发给他的负责人，取的时候直接读值即可
```
func bonus(n int, leadership [][]int, operations [][]int) []int {
    m := make(map[int][]int)
    lead := make(map[int]int)
    total := make([]int, n+1)
    ret := []int{}
    for i := 0; i < len(leadership); i++ {
        m[leadership[i][0]] = append(m[leadership[i][0]], leadership[i][1])
        lead[leadership[i][1]] = leadership[i][0]
    }
    for i := 0; i < len(operations); i++ {
        if operations[i][0] == 1 {
            add(total, lead, operations[i][1], operations[i][2])
        } else if operations[i][0] == 2 {
            find(m, total, lead, operations[i][1], operations[i][2])
        } else {
            ret = append(ret, total[operations[i][1]])
        }
    }
    return ret
}

func add(total []int, lead map[int]int, now, lt int) {
    total[now] = (total[now] + lt) % 1000000007
    if v, ok := lead[now]; ok {
        add(total, lead, v, lt)
    }
}

func find(m map[int][]int, total []int, lead map[int]int, now, lt int) {
    add(total, lead, now, lt)
    for _, v := range m[now] {
        find(m, total, lead, v, lt)
    }
}
```
