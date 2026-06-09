把权重看作是路程，每个数字的权重就表示对应的距离。


比如 w = []int{1,2,3}

那么这段路就是 0 1 1 2 2 2

构造的时候记录每个数字的开始和结束节点。

pick的时候，首先获取一个路程总长内的随机值，然后找到这个随机值对应的路段
```
type Solution struct {
    rd *rand.Rand
    total int64
    node []Node
}

type Node struct {
    start, end int64
}


func Constructor(w []int) Solution {
    var total int64
    node := make([]Node, len(w))
    for i := 0; i < len(w); i++ {
        node[i] = Node{total, total + int64(w[i])}
        total += int64(w[i])
    }
    return Solution{rand.New(rand.NewSource(time.Now().UnixNano())), total, node}
}


func (this *Solution) PickIndex() int {
    idx := this.rd.Int63n(this.total)%this.total
    for i := 0; i < len(this.node); i++ {
        if this.node[i].start <= idx && this.node[i].end > idx {
            return i
        }
    }
    return -1
}

```
