### 解题思路
注意小顶堆比较的规则

### 代码

```golang
import (
    "container/heap"
    "strings"
)

type Item struct {
    word string
    count int
}

type MinHeap []*Item

func (m MinHeap) Len() int {
    return len(m)
}

func (m MinHeap) Less(i, j int) bool {
    if m[i].count == m[j].count {
        return strings.Compare(m[i].word, m[j].word) > 0
    }
    return m[i].count < m[j].count
}

func (m MinHeap) Swap(i, j int) {
    m[i], m[j] = m[j], m[i]
}

func (m *MinHeap) Push(x interface{}) {
    item := x.(*Item)
    *m = append(*m, item)
}

func (m *MinHeap) Pop() interface{} {
    n := len(*m)
    old := *m
    last := old[n-1]
    old[n-1] = nil
    *m = old[:n-1]
    return last
}


func topKFrequent(words []string, k int) []string {
    if words == nil || len(words) == 0 || k <= 0{
        return nil
    }
    //用map统计每个单词出现的次数
    var fm = make(map[string]int)
    for _, word := range words {
        fm[word] = fm[word] + 1
    }

    var topk int = k 
    if len(fm) < topk {
        topk = len(fm)
    }

    //利用小顶堆维持k个最高频的元素
    var i int
    var h = make(MinHeap, 0, topk)
    for word, count := range fm {
        i++
        if i <= topk {
            item := &Item{
                word: word,
                count: count,
            }
            heap.Push(&h, item)
        } else {
            item := &Item{
                word: word,
                count: count,
            }
            heap.Push(&h, item)
            heap.Pop(&h) 
        }
    }

    //遍历小顶堆中的元素，逆序放到数组中
    var result = make([]string, topk)
    for i := topk-1; i >= 0; i-- {
        top := heap.Pop(&h).(*Item)
        result[i] = top.word
    }
    return result
}
```