```
func maxAliveYear(birth []int, death []int) int {
    n := len(birth)
    if n == 0 {
        return 0
    }
    person := make([][2]int, n)
    for i := 0; i < n; i++ {
        person[i] = [2]int{birth[i], death[i]}
    }
    sort.Slice(person, func(i, j int) bool {
        return person[i][0] < person[j][0]
    })
    var res int
    var maxCnt int
    pq := priority_queue{}
    cnt := 0
    for i := 0; i < n; i++ {
        if len(pq) == 0 || pq[0][0] >= person[i][0] {
            cnt++
            heap.Push(&pq, [3]int{person[i][1], person[i][0], cnt})
        } else {
            pq[0][0] = person[i][1]
            heap.Fix(&pq, 0)
        }
    }
    for i := 0; i < len(pq); i++ {
        if pq[i][2] > maxCnt {
            maxCnt = pq[i][2]
            res = pq[i][1]
        } else if pq[i][2] == maxCnt {
            res = min(res, pq[i][1])
        }
    }
    return res
}
func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}

type priority_queue [][3]int
func (pq priority_queue) Len() int {
    return len(pq)
}
func (pq priority_queue) Less(i, j int) bool {
    return pq[i][0] < pq[j][0]
}
func (pq priority_queue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}
func (pq *priority_queue) Push(v interface{}) {
    *pq = append(*pq, v.([3]int))
}
func (pq *priority_queue) Pop() interface{} {
    nlen := len(*pq)
    val := (*pq)[nlen-1]
    *pq = (*pq)[:nlen-1]
    return val
}
```
