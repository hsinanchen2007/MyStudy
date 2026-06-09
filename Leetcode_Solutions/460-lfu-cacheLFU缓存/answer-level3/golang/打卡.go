### 解题思路
此处撰写解题思路

### 代码

```golang
type LFUCache struct {
    Table map[int]*Node
    Freq map[int]*List
    MinFreq int
    Capacity int
    Size int
}


func Constructor(capacity int) LFUCache {
    return LFUCache{
        Table: make(map[int]*Node),
        Freq: make(map[int]*List),
        Capacity: capacity,
    }
}


func (this *LFUCache) Get(key int) int {
    res, ok := this.Table[key]
    if !ok {
        return -1
    }
    this.incrementFreq(res)
    return res.Val
}


func (this *LFUCache) Put(key int, value int)  {
    if this.Capacity == 0 {
        return
    }
    if res, ok := this.Table[key]; ok {
        this.Table[key].Val = value
        this.incrementFreq(res)
        return
    }
    if this.Size == this.Capacity {
        this.removeMin()
    }
    item := &Node{
        Key: key,
        Val: value,
        Freq: 1,
    }
    this.addItem(item)
}

func (this *LFUCache) incrementFreq(item *Node) {
    this.Freq[item.Freq].Remove(item)
    if item.Freq == this.MinFreq && this.Freq[item.Freq].Size == 0 {
        this.MinFreq++
    }
    item.Freq++
    if this.Freq[item.Freq] == nil {
        this.Freq[item.Freq] = NewList()
    }
    this.Freq[item.Freq].PushBack(item)
}

func (this *LFUCache) addItem(item *Node) {
    if this.Freq[1] == nil {
        this.Freq[1] = NewList()
    }
    this.Freq[1].PushBack(item)
    this.Table[item.Key] = item
    this.MinFreq = 1
    this.Size++
}

func (this *LFUCache) removeMin() {
    toRemove := this.Freq[this.MinFreq].Front()
    this.Freq[this.MinFreq].Remove(toRemove)
    delete(this.Table, toRemove.Key)
    if this.Freq[this.MinFreq].Size == 0 {
        this.MinFreq++
    } 
    this.Size--
}

type Node struct {
    Key, Val int
    Freq int
    Prev, Next *Node
}

type List struct {
    Head, Tail *Node
    Size int
}

func NewList() *List {
    head := &Node{}
    tail := &Node{Prev: head}
    head.Next = tail
    return &List{
        Head: head,
        Tail: tail,
    }
}

func (l *List) PushBack(node *Node) {
    node.Prev, node.Next = l.Tail.Prev, l.Tail
    node.Prev.Next, node.Next.Prev = node, node
    l.Size++
}

func (l *List) Remove(node *Node) {
    node.Prev.Next, node.Next.Prev = node.Next, node.Prev
    l.Size--
}

func (l *List) Front() *Node {
    return l.Head.Next
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```