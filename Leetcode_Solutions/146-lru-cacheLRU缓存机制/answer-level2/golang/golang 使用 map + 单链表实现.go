### 解题思路
#### put

> 1. 使用 map 检查 key 是否在 lru中
> 2. 如果存在，那么修改这个节点A的数据域，并将节点 A 移动到链表的头结点。（这里说是移动实际上有两个步骤，先将节点A在原位置删除，再将节点A移动到头节点）；并设置 map 的 kv
> 3. 如果不存在，那么新建一个节点，并将其添加到链表的头节点；并设置 map 的kv
> 4. 如果以上操作后，链表长度超过阈值 capacity ，那么将链表最后一个节点删除，并删除 map 中相同 key的节点

#### get

> 1. 使用 map 检查key 是否在 lru 中
> 2. 如果存在，那么修改这个节点A的数据域，并将节点 A 移动到链表的头结点。（这里说是移动实际上有两个步骤，先将节点A在原位置删除，再将节点A移动到头节点）
> 3. 如果不存在，那么返回 -1

这是一个时间复杂度较差的实现，但是使用比较标准的map + 单链表来处理lru的问题

### 代码

```golang
type Node struct {
	key   int
	value int
	Next  *Node
}

type LRUCache struct {
	capacity int
	size     int
	dataMap  map[int]*Node
	dataHead *Node
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		capacity: capacity,
		dataMap:  make(map[int]*Node, capacity),
	}
}

func (this *LRUCache) Get(key int) int {
	data, ok := this.dataMap[key]
	if !ok {
		return -1
	}
	// shift
	res := data.value
	this.shiftIn(data)
	return res
}


func (this *LRUCache) Put(key int, value int) {
	data, ok := this.dataMap[key]

	if !ok {
		addNode := &Node{key: key, value: value}
		this.addAtHead(addNode)
		this.dataMap[key] = addNode
		return
	}
	// 用新的 value 更新数据域
	data.value = value
	this.shiftIn(data)
}

// shift 这个shift方法会超时哦
func (this *LRUCache) shift(data *Node) {
	if this.dataHead == nil {
		this.dataHead = data
		return
	}
	// 在链表中删除节点
	this.removeKey(data)
	// data 移动到头结点
	data.Next = this.dataHead
	this.dataHead = data
}

func (this *LRUCache) removeKey(data *Node) {
	node := this.dataHead
	// 找pre
	pre := node
	for node.key != data.key {
		pre = node
		node = node.Next
	}
	pre.Next = node.Next
}

// 常数时间内删除
func (this *LRUCache) shiftIn(data *Node) {
	if this.dataHead == nil || this.size == 1 {
		this.dataHead = data
		return
	}
	// 在链表中删除节点
	data = this.removeKeyIn(data)
	// data 移动到头结点
	data.Next = this.dataHead
	this.dataHead = data
}

func (this *LRUCache) removeKeyIn(data *Node) (newData *Node) {
	if data.Next == nil {
		this.removeKey(data)
		return data
	}

	next := data.Next
	// 先将data 和 data.Next 交换数据域，这样data.Next就好删除了
	data.key, next.key = next.key, data.key
	data.value, next.value = next.value, data.value
	data.Next = next.Next

	this.dataMap[data.key] = data
	this.dataMap[next.key] = next
	return next
}

func (this *LRUCache) addAtHead(node *Node) {
	node.Next = this.dataHead
	this.dataHead = node
	this.size++
	if this.isOverflow() {
		this.deleteOverflow()
	}
}

func (this *LRUCache) isOverflow() bool {
	return this.size > this.capacity
}

func (this *LRUCache) deleteOverflow() {
	node := this.dataHead
	if node == nil {
		return
	}
	pre := node
	for node.Next != nil {
		pre = node
		node = node.Next
	}
	pre.Next = nil
	delete(this.dataMap, node.key)
	this.size --
}
```