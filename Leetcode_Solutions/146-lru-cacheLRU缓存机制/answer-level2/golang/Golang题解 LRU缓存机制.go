双链表在删除和添加节点的时间复杂度是O(1)，查找的时间复杂度是 O(n)，为了加快查找的速度，使用map保存节点。如果理解双向链表，就能理解这道题。

```
type Node struct {
	key, value int
	pre, next *Node
}

type LRUCache struct {
	capacity int
	mapCache map[int]*Node
	head, end *Node
}


func Constructor(capacity int) LRUCache {
	mapCache := make(map[int]*Node, capacity)
	return LRUCache{
		capacity:capacity,
		mapCache: mapCache,
		head:nil,
		end:nil,
	}
}

/**
 * 获取节点的值
 * 1.判断 key在mapCache中是否存在
 * 存在，获取节点，调用 remove()移除节点，调用 setHeader() 设置头节点
 * 不存在，返回-1
 */
func (this *LRUCache) Get(key int) int {
	node, ok := this.mapCache[key]
	if !ok {
		return -1
	}
	this.remove(node)
	this.setHeader(node)
	return node.value
}

/**
 * 添加节点
 * 1.判断key在 mapCache是否存在
 * 存在，获取节点，更新值，调用 remove()移除节点，调用 setHeader()设置头节点
 * 不存在，判断mapCache是否超出容量，超出 获取 尾节点(end)，从mapCache删除，并调用remove()移除节点
 * 之后创建节点，添加到mapCache，setHeader()设置头节点
 */
func (this *LRUCache) Put(key int, value int)  {
	if node, ok := this.mapCache[key]; ok {
		node.value = value
		this.remove(node)
		this.setHeader(node)
	} else {
		if len(this.mapCache) >= this.capacity {
			delete(this.mapCache, this.end.key)
			this.remove(this.end)
		}
		node := &Node{key:key, value:value}
		this.mapCache[key] = node
		this.setHeader(node)
	}
}

/**
 * 移除节点
 * 1.判断前驱节点是否为nil
 * 是，说明此节点是头节点(head)，对head进行操作
 * 否，不是头节点，node->pre->next = node->next
 * 2. 判断后继节点是否为nil
 * 是，此节点是尾节点(end)，对尾节点处理
 * 否，node->next->pre = node->pre
 */
func (this *LRUCache) remove(node *Node) {
	if node.pre == nil {
		this.head = node.next
	} else {
		node.pre.next = node.next
	}

	if node.next == nil {
		this.end = node.pre
	} else {
		node.next.pre = node.pre
	}
}

/**
 * 设置头节点
 * node->pre = nil
 * 1.判断 头节点(head)是否为空
 * 为空直接设置；不为空，将当前头节点(head)设置为链表第二个节点，node设置为头节点
 * 2.判断 尾节点(end)是否为空
 * 为空直接设置
 */
func (this *LRUCache) setHeader(node *Node) {
	node.pre = nil
	if this.head == nil {
		this.head = node
	} else {
		this.head.pre, node.next = node, this.head
		this.head = node
	}

	if this.end == nil {
		this.end = node
	}
}



```
