### 解题思路
此处撰写解题思路
go 双链表加map解法
俩个map 
1 key  *Node  保存key和对应的node地址
2  freq  *DoubleNode  保存频率和对应DoubleNode地址
关键是注意处理最小频率问题 
### 代码

```golang
type LFUCache struct {
    capacity    int         // 容量
    minfreq     int         // 目前最小频率
    size        int          // 目前缓存元素个数
    cache       map[int]*Node  // key  *Node  保存key和对应的node地址
    freq        map[int]*DoubleNode  // freq  *DoubleNode  保存频率和对应DoubleNode地址
}

// 双链表节点
type Node struct {
    key, value, freq    int
    prev, next          *Node
}

// 双链表及双链表相关操作
type DoubleNode struct {
    head, tail  *Node
    size        int
}

// 删除双链表最后一个节点
func (this *DoubleNode) removeTail() *Node{
    prev := this.tail.prev
    prev.prev.next = this.tail
    this.tail.prev = prev.prev
    return prev
}

// 删除双链表中的节点
func (this *DoubleNode) remove(node *Node) {
    prev := node.prev
    prev.next = node.next
    prev.next.prev = prev
}

// 双链表添加节点
func (this *DoubleNode) add(node *Node) {
    next := this.head.next
    next.prev = node
    this.head.next = node
    node.next = next
    node.prev = this.head
}

// LFUCache 相关操作
func (this *LFUCache) remove(node *Node) {
    dnode := this.freq[node.freq]
    dnode.remove(node)
    dnode.size--
}

func (this *LFUCache) add(node *Node) {
    if dnode, ok := this.freq[node.freq]; ok {
        dnode.add(node)
        dnode.size++
    }else {
        dnode = &DoubleNode{&Node{}, &Node{}, 0}
        dnode.head.next = dnode.tail
        dnode.tail.prev = dnode.head
        dnode.add(node)
        dnode.size++
        this.freq[node.freq] = dnode
    }   
}

func (this *LFUCache) removeMinFreq() {
    dnode := this.freq[this.minfreq]
    key := dnode.removeTail().key
    dnode.size--
    delete(this.cache, key)
}


func Constructor(capacity int) LFUCache {

    return LFUCache{
                    capacity :   capacity,
                    minfreq  :   0,
                    size     :   0,
                    cache    :   make(map[int]*Node),
                    freq     :   make(map[int]*DoubleNode),
                }

}

func (this *LFUCache) Get(key int) int {
    // 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
    // 若key存在， 把原有key从保存他的双链表中删除（如果删除后双链表size为0， 需要处理最小freq）， 添加到频率增1的双链表中。
    if node, ok := this.cache[key]; ok {
        this.remove(node)
        if node.freq == this.minfreq && this.freq[node.freq].size == 0 {
            this.minfreq++
        }
        node.freq++
        this.add(node)
        return node.value
    }
    return -1
}


func (this *LFUCache) Put(key int, value int)  {
    if this.capacity == 0 {
        return
    }
    // 创建新节点
    newnode := &Node{key, value, 1, nil, nil}
    // 如果key 不存在
    if node, ok := this.cache[key]; !ok {
        if this.size < this.capacity{
            this.add(newnode)
            this.size++
            this.minfreq = 1            
        }else {
            // 删除minfreq
            this.removeMinFreq()
            this.minfreq = 1
            this.add(newnode)
        }
    }else {
        this.remove(node)
        if this.minfreq == node.freq && this.freq[node.freq].size == 0 {
            this.minfreq++
        }
        newnode.freq =  node.freq+1
        this.add(newnode)
    }
    this.cache[key] = newnode

}


/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```