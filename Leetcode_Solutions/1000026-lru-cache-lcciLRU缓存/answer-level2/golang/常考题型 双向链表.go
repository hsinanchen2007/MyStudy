```go
type LRUCache struct {
	head *NodeList
	tail *NodeList
	capacity int
	cache map[int]*NodeList
}

type NodeList struct {
	val int
	key int
	pre *NodeList
	next *NodeList
}

func (c *NodeList) remove() {
	c.next.pre = c.pre
	c.pre.next = c.next
}

func(c *LRUCache) setHeader(node *NodeList) {
	c.head.next.pre = node
	node.next = c.head.next
	node.pre = c.head
	c.head.next = node

}


func Constructor(capacity int) LRUCache {
	lru := LRUCache{head: new(NodeList),
					tail: new(NodeList),
					capacity: capacity,
					cache: make(map[int]*NodeList, capacity)}

	lru.tail.pre = lru.head
	lru.head.next = lru.tail
	return lru
}


func (this *LRUCache) Get(key int) int {
	if n, ok := this.cache[key]; !ok {
		return -1
	} else {
		n.remove()
		this.setHeader(n)
		return n.val
	}
}


func (this *LRUCache) Put(key int, value int)  {
    if node, ok := this.cache[key]; ok {
        node.remove()
        delete(this.cache, key)
    } else if len(this.cache) >= this.capacity {
		toRemove := this.tail.pre
		toRemove.remove()
		delete(this.cache, toRemove.key)

	}
	newNode := &NodeList{val:value, key:key}
	this.setHeader(newNode)
	this.cache[key] = newNode
}

```