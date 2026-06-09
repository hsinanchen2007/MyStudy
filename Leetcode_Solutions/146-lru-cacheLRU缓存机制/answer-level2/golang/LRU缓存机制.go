### 解题思路
map+带头节点和尾节点的双向链表

### 代码

```golang
type LRUCacheNode struct {
	key   int
	value int
	prev  *LRUCacheNode
	next  *LRUCacheNode
}

// 双向链表+map
type LRUCache struct {
	md       map[int]*LRUCacheNode
	len      int
	capacity int
	head     *LRUCacheNode
	tail     *LRUCacheNode
}

func Constructor(capacity int) LRUCache {
	lc := LRUCache{
		md:       make(map[int]*LRUCacheNode),
		capacity: capacity,
		len:      0,
	}

	lc.head = &LRUCacheNode{}
	lc.tail = &LRUCacheNode{}
	lc.head.prev = nil
	lc.head.next = lc.tail
	lc.tail.prev = lc.head
	lc.tail.next = nil

	return lc
}

func (this *LRUCache) Get(key int) int {
	// 如果键不存在，则返回-1
	if _, exist := this.md[key]; !exist {
		return -1
	}

	// 存在，则将节点移到链表头部
	this.MoveToHead(this.md[key])
	return this.md[key].value
}

func (this *LRUCache) Put(key int, value int) {
	// 首先判断是否存在此key，如果存在则更新并移动到头部
	if _, exist := this.md[key]; exist {
		this.md[key].value = value
		this.MoveToHead(this.md[key])
	} else { // 不存在此key，插入新节点到头部
		// 检查是否已达到最大容量，达到则淘汰尾节点
		if this.len > this.capacity {
			panic("impossible")
		}

		if this.len == this.capacity {
			this.AbandonTail()
			this.len--
		}

		// 添加新节点到头部
		node := &LRUCacheNode{
			key:   key,
			value: value,
		}
		this.AddToHead(node)
		this.md[key] = node
		this.len++
	}
}

func (this *LRUCache) AddToHead(node *LRUCacheNode) {
	node.prev = this.head
	node.next = this.head.next
	this.head.next.prev = node
	this.head.next = node
}

func (this *LRUCache) MoveToHead(node *LRUCacheNode) {
	this.RemoveNode(node)
	this.AddToHead(node)
}

func (this *LRUCache) AbandonTail() {
	if this.len > 0 {
		delete(this.md, this.tail.prev.key)
		this.RemoveNode(this.tail.prev)
	}
}

func (this *LRUCache) RemoveNode(node *LRUCacheNode) {
	node.prev.next = node.next
	node.next.prev = node.prev

	node.prev = nil
	node.next = nil
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```