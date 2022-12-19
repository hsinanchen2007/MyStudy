### 解题思路

#### 时间复杂度分析：
双向链表实现添加、删除 O(1)
哈希表实现查找 O(1)

#### 空间复杂度分析
堆中开辟内存空间，存放节点，有多少个节点就需要开辟多少内存，
哈希表和双向链表都是利用指针引用节点对象，所以，空间复杂度为 O(n)。

### 代码

```golang




type LinkNode struct {
    key, val int 
    pre, next *LinkNode
}

type LRUCache struct {
    m map[int]*LinkNode // 指向哈希表的指针
    cap int // 长度
    head, tail *LinkNode // 两个哨兵
}

func Constructor(capacity int) LRUCache {
    head := &LinkNode{0, 0, nil, nil}
    tail := &LinkNode{0, 0, nil, nil}
    head.next = tail
    tail.pre = head
    return LRUCache{make(map[int]*LinkNode), capacity, head, tail}
}


func (this *LRUCache) Get(key int) int {
    cache := this.m
    if node, exist := cache[key]; exist {
        this.moveToHead(node)
        return node.val
    }else {
        return -1
    }
}
func (this *LRUCache) moveToHead(node *LinkNode) {
    head := this.head
    // 从当前位置删除节点
    node.pre.next = node.next
    node.next.pre = node.pre
    // 将节点插入头部
    node.next = head.next
    head.next.pre = node
    node.pre = head
    head.next = node
}

func (this *LRUCache) Put(key int, value int)  {
    head := this.head
    tail := this.tail
    cache := this.m
    if node, exist := cache[key]; exist {// 如果已经存在对应的节点，要将对应的元素交换到头部；并更新值（值可能变了）
        node.val = value
        this.moveToHead(node)
    }else {// 节点不存在
        // 创建节点
        node := &LinkNode{key, value, nil, nil}
        // 判断缓存容量是否已经满了
        if len(cache) == this.cap {
            // 删除最后的元素
            delete(cache, tail.pre.key)
            tail.pre.pre.next = tail
            tail.pre = tail.pre.pre
        }
        // 将节点放到头部
        node.next = head.next
        node.pre = head
        head.next.pre = node
        head.next = node
        // 参入哈希表中
        cache[key] = node
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```