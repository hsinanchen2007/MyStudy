### 解题思路
用双向链表实现，思路还是比较简单的具体看代码应该能明白。（YYCache相同实现方式）。

### 代码

```swift
class DLikedNode {
    var val: Int
    var next: DLikedNode?
    var pre: DLikedNode?
    var key: Int?
    init(val: Int, key: Int? = nil, next: DLikedNode? = nil, pre: DLikedNode? = nil) {
        self.val = val
        self.key = key
        self.next = next
        self.pre = pre
    }
}

class LRUCache {

    var capacity = 0
    var count = 0
    let first = DLikedNode(val: -1)
    let last = DLikedNode(val: -1)
    
    var hash = Dictionary<Int, DLikedNode>()
    
    init(_ capacity: Int) {
        self.capacity = capacity
        first.next = last
        first.pre = nil
        
        last.pre = first
        last.next = nil
    }
    
    func moveToHead(node: DLikedNode) {
        let pre = node.pre
        let next = node.next
        
        pre?.next = next
        next?.pre = pre
        
        node.next = first.next
        first.next?.pre = node
        first.next = node
        node.pre = first
    }
    
    func removeLastNode() {
        let node = last.pre
        node?.pre?.next = last
        last.pre = node?.pre
        count -= 1
        hash[node!.key!] = nil
    }
    
    func addNewNode(key: Int, node: DLikedNode) {
        moveToHead(node: node)
        count += 1
        hash[key] = node
    }
    
    func get(_ key: Int) -> Int {
        let node = hash[key]
        if let n = node {
            moveToHead(node: n)
            return n.val
        }else {
            return -1
        }
    }
    
    func put(_ key: Int, _ value: Int) {
        let node = hash[key]
        if let n = node {
            // 挪到第一位
            n.val = value
            moveToHead(node: n)
        }else {
            let newNode = DLikedNode(val: value, key: key)
            // 判断容量
            if count >= capacity {
                // 移除最后一个节点
                removeLastNode()
                // 新节点插入头结点后
                addNewNode(key: key, node: newNode)
            }else {
                // 新节点插入头结点后
                addNewNode(key: key, node: newNode)
            }
        }
    }
}
```