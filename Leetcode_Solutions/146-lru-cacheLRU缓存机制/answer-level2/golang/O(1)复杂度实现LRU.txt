### 思路
使用双向链表+哈希实现
### 完整代码
```
type Node struct {
	Key      int
	Val      int
	PrevNode *Node
	Next     *Node
}

type LRUCache struct {
    Capacity int
	Cache map[int]*Node
	Head *Node
	Tail *Node
    IdelNode *Node // 避免每put一次就新创建一个结构体，可以把超出capacity长度，丢弃的node，拿来复用,这样最多需要capacity+1 个node结构体内存
}


func Constructor(capacity int) LRUCache {
    	return LRUCache{
		Capacity: capacity,
		Cache: make(map[int]*Node),
	}
}


func (this *LRUCache) Get(key int) int {
	node, ok := this.Cache[key]
	if !ok {
		return -1
	}
	if this.Capacity == 1 || len(this.Cache) == 1 {
		return node.Val
	}
	if this.Tail == node { 
		return node.Val
	}
	// 把node从链中断开
	if this.Head == node { 
		this.Head = node.Next
	}else {
		node.PrevNode.Next = node.Next
		node.Next.PrevNode = node.PrevNode
	}

	// 把node放到最后
	node.PrevNode = this.Tail
	node.Next = nil
	this.Tail.Next = node
	this.Tail = node
	return node.Val
}


func (this *LRUCache) Put(key int, value int)  {
	if this.Capacity <= 0 {
		return
	}
	// Get方法回自动把存在的值移动到最后
	if this.Get(key) != -1 {
		this.Tail.Val = value
		return
	}
	var node *Node
	if len(this.Cache) <= this.Capacity {
		node = &Node{}
	}else{
		node = this.IdelNode
	}
	node.Key = key
	node.Val = value
	this.Cache[key] = node
	if this.Head == nil {
		this.Head = node
		this.Tail = node
		return
	}
	node.PrevNode = this.Tail
	this.Tail.Next = node
	this.Tail = node
	if len(this.Cache) - 1/*为了减少重复代码 先执行map赋值了 所以这里要-1*/ == this.Capacity {
		delete(this.Cache, this.Head.Key)
		headNode := this.Head
		this.Head = headNode.Next
		this.IdelNode = headNode
		this.IdelNode.PrevNode = nil
		this.IdelNode.Next = nil
	}
	return
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/82b347cd2fd550dadd50feb4349ab6de299a9df8bb39b15e10564cf3a3eec67b-image.png)