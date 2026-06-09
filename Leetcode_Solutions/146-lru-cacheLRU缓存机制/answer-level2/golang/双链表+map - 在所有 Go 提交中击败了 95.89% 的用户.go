### 解题思路
双链表+map

### 代码

```golang
type Node struct {
    Key, Value int
    Pre, Next *Node
}

type DoublyLinkedList struct {
    Length int
    Head, Tail *Node // two dummy nodes
}

func NewDoublyLinkedList() *DoublyLinkedList {
    head := &Node{
        Key: 0,
        Value: 0,
    }
    tail := &Node{
        Key: 0,
        Value: 0,
    }
    head.Next = tail
    tail.Pre = head
    return &DoublyLinkedList{
        Length: 0,
        Head: head,
        Tail: tail,
    }
}

func (list *DoublyLinkedList) addToHead(node *Node) {
    if node == nil {
        return
    }
    if list.Length == 0 {
        list.Head.Next = node
        list.Tail.Pre = node
        node.Pre = list.Head
        node.Next = list.Tail
        list.Length++
        return
    }
    next := list.Head.Next
    next.Pre = node
    node.Next = next
    list.Head.Next = node
    node.Pre = list.Head
    list.Length++
}

func (list *DoublyLinkedList) remove(node *Node) {
    if list.Length == 0 {
        return
    }
    pre := node.Pre
    next := node.Next
    pre.Next = next
    next.Pre = pre
}

func (list *DoublyLinkedList) removeTail() *Node {
    if list.Length == 0 {
        return nil
    }
    oldTail := list.Tail.Pre
    tail := list.Tail.Pre.Pre
    tail.Next = list.Tail
    list.Tail.Pre = tail
    list.Length--
    return oldTail
}

func (list *DoublyLinkedList) moveToHead(node *Node) {
    if list.Length == 0 || list.Length == 1 {
        return
    }
    pre := node.Pre
    next := node.Next
    pre.Next = next
    next.Pre = pre

    oldHead := list.Head.Next
    oldHead.Pre = node
    node.Next = oldHead
    list.Head.Next = node
    node.Pre = list.Head
}

type LRUCache struct {
    Capacity int
    Length int
    cache map[int]*Node
    list *DoublyLinkedList
}

func Constructor(capacity int) LRUCache {
    length := 0
    cache := make(map[int]*Node, 0)
    list := NewDoublyLinkedList()
    LRUCache := LRUCache{
        Capacity: capacity,
        Length: length,
        cache: cache,
        list: list,

    }
    return LRUCache
}

func (this *LRUCache) Get(key int) int {
    node, prs := this.cache[key]
    if !prs {
        return -1
    }
    this.list.moveToHead(node)
    return node.Value
}

func (this *LRUCache) Put(key int, value int)  {
    node := &Node{
        Key: key,
        Value: value,
    }
    if this.Length == this.Capacity {
        oldNode, prs := this.cache[key]
        if !prs {
            tail := this.list.removeTail()
            delete(this.cache, tail.Key)
            this.cache[key] = node
            this.list.addToHead(node)
        } else {
            this.list.remove(oldNode)
            this.cache[key] = node
            this.list.addToHead(node)
        }
    } else if this.Length < this.Capacity {
        oldNode, prs := this.cache[key]
        if !prs {
            this.cache[key] = node
            this.list.addToHead(node)
            this.Length++
        } else {
            this.list.remove(oldNode)
            this.list.addToHead(node)
            this.cache[key] = node
        }
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```