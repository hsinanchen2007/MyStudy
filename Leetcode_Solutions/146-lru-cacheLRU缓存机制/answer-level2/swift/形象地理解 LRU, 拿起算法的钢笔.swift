

LRU 还是有用的，缓存管理的时候，有时用到。内存有限，聚焦在重点的资源上

（ 还有面试 ）

### 学习 LRU, 首先要建立直观的认识

LRU 的描述很简洁，容量有限，最近使用到的资源，排前面。

> 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

> 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。

> 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

##### 模拟一下

下面有两个绿色的格子，代表这个 LRU 的容量，是两个

先放节点 1 ，容量 2， 当前是空的，直接放

![0.png](https://pic.leetcode-cn.com/e80e96f542c4f50a34188c34dec8068fdf0f38998f1761d49ad49a6a85caaa4a)

再放节点 2 ，容量 2， 当前个数 1，可以直接放

![1.png](https://pic.leetcode-cn.com/c28029c35d1df6185973be1a85f241150a497d210b8c50a9f5ddc7c99b31698c)

![2.png](https://pic.leetcode-cn.com/a928427a594f4553558568a7f68bd769f672c162d6367f90c4bd63c23c522985)

然后读取节点 1，当前哈希表中有，返回正常，该节点为最新使用节点

![3.png](https://pic.leetcode-cn.com/e6d91d11c8a589500a0438b603eaf609c29b1c23b196a76594f4bfe6583dc2b7)

![4.png](https://pic.leetcode-cn.com/4a5d0d05acc8e1bc754adda41feb0cba8855086a0c030c4a966db4d129f9c872)

放入节点 3， 当前个数达到容量，需要删除一个最久使用的，才能插入新的。

怎么删除，从当前节点出发，顺着箭头数。数到容量个数的，不重复节点，就都要的。（记得跳过，读取不到值的节点 ）

数到容量个数的，不重复节点的，前面的那一个不重复节点，就是要被删除的。（记得跳过，读取不到值的节点 ）

因为当前节点，是最新使用的，越是箭头方向，越是以前有用到，（ 同一元素，第一次数到，为有效 ）

![5.png](https://pic.leetcode-cn.com/7bebd3bdc57c5acf56d79d420f5c93ae87c9a2caf8271cbcb15fc404a4912de4)

删除节点 2

![6.png](https://pic.leetcode-cn.com/27415ff0a2a174d796675031bd04f2c030ef33d7ffac1c35e6d6e70aa461c62d)

读取节点 2，发现取不到，返回 -1

![7.png](https://pic.leetcode-cn.com/87b5d3e22999f2fa6b7c409b87379151118c1c143f1ec1739a6c430dfe7cfa73)

![8.png](https://pic.leetcode-cn.com/9e487bd1c13d9d5c9aeb1263b56dd149d3b9cb5a0f5d392485d4e1e6fff6b345)

最终：

![9.png](https://pic.leetcode-cn.com/4e51de17914d64a5ec94b38c2acbc305539585a2622652fa2eb44c1b7c8d9cf9)



### 数据结构部分: 

采用了哈希表 （ Swift 中的字典 ）和双链表。

##### Key - Value 存取，当然要用哈希表。

#####  要保证新插入和新使用的元素在前，很久没使用的元素在后，可以来一个链表。

头部元素，最近使用。尾部方向元素，最近越来越少用到


元素个数超过了容量，就要删除尾部元素，需要有一个尾指针记录，有了尾指针，要删除最后的元素，就要找到他的上一个指针来操作，就要有前驱。（或者上一个指针的上一个来操作）


有了前驱。链表元素自然要找到他的下一个，也就是后继。（链表的固有属性）

链表存在前驱与后继，就是双链表了。

##### 另一角度，双链表里面的节点，可以轻松实现自删除，不需要其他指针的协助

### 简单粗暴，实现一个 LRU, O ( 1 ) 复杂度

LRU 可以简单分为两部分，数据的写入与读取

先实现写入，写入了，进程里面才有数据，方便调试读取

##### 设计存入的部分

分情况处理，

* 如果要插入的元素，已经在链表里面了，根据 key.

要维持链表的 LRU 有序，就要把他放在最前面，就要改他的前后指针，以及相关节点的。

先删除他，再把他插入头节点，

还要更新他的 value, 也许这个 key 的值变了。



* 如果要插入的元素，不在链表里面了，根据 key.

又要考虑三种情况，

如果是插入第一个元素，要先建立结构，假的头部节点，后面是假的尾节点

如果已经存在的元素满了，要删除最后面的元素，也就是最近少用到的

最后一种情况，一切正常。把新的节点，插入头部第一个。
```


class DLinkedNode {
    // 这个是，删除尾节点，要同步哈希表。哈希表也要对应删除的时候，用到
    let key: Int
    var val: Int
    var prior: DLinkedNode?
    var next: DLinkedNode?
    
    init(_ key: Int, value: Int) {
        self.key = key
        val = value
    }

}


class LRUCache {
    
    var dummyHead = DLinkedNode(0, value: 0)
    var dummyTail = DLinkedNode(0, value: 0)
    var capacity: Int
    var container = [Int: DLinkedNode]()
    var hasCount: Int = 0

    init(_ capacity: Int) {
        self.capacity = capacity
    }
    
    func put(_ key: Int, _ value: Int) {
       // 先设计存的部分
    }
    
    func insertHead(_ node: DLinkedNode){
        let former = dummyHead.next
        former?.prior = node
        dummyHead.next = node
        node.prior = dummyHead
        node.next = former
    }
    
    func deleteNode(_ node: DLinkedNode){
        node.prior?.next = node.next
        node.next?.prior = node.prior
        node.prior = nil
        node.next = nil
    }
    
    func deleteTail(){
        if let toDel = dummyTail.prior{
            toDel.prior?.next = dummyTail
            dummyTail.prior = toDel.prior
            container.removeValue(forKey: toDel.key)
        }
    }
}


```

##### 设计读取的部分

读取部分，相对简单

哈希表中没有 key, 就返回 -1 ，没有

哈希表中存在 key， 就找到对应的节点，返回值。同时把该节点更新到头部第一个节点。
也就是在链表中，先删除，再插入到头部。


```


class DLinkedNode {
    let key: Int
    var val: Int
    var prior: DLinkedNode?
    var next: DLinkedNode?
    
    init(_ key: Int, value: Int) {
       self.key = key
        val = value
    }

}


class LRUCache {
    
    var dummyHead = DLinkedNode(0, value: 0)
    var dummyTail = DLinkedNode(0, value: 0)
    // 这个记录设定的容量
    var capacity: Int
    var container = [Int: DLinkedNode]()
   // 这个记录实际的元素个数
    var hasCount: Int = 0

    init(_ capacity: Int) {
        self.capacity = capacity
    }
    
    func get(_ key: Int) -> Int {
     // 再设计取的部分
    }

    func put(_ key: Int, _ value: Int) {
        if let node = container[key]{
            // 包含，就换顺序
            // 还有一个更新操作
            node.val = value
            deleteNode(node)
            insertHead(node)
        }
        else{
            if hasCount == 0{
                // 建立结构
                dummyHead.next = dummyTail
                dummyTail.prior = dummyHead
            }
            if hasCount >= capacity{
                // 超过，就处理
                hasCount -= 1
                deleteTail()
            }
            hasCount += 1
            // 不包含，就插入头节点
            let node = DLinkedNode(key, value: value)
            insertHead(node)
            container[key] = node
        }
    }
    
    func insertHead(_ node: DLinkedNode){
        let former = dummyHead.next
        former?.prior = node
        dummyHead.next = node
        node.prior = dummyHead
        node.next = former
    }
    
    func deleteNode(_ node: DLinkedNode){
        node.prior?.next = node.next
        node.next?.prior = node.prior
        node.prior = nil
        node.next = nil
    }
    
    func deleteTail(){
        if let toDel = dummyTail.prior{
            toDel.prior?.next = dummyTail
            dummyTail.prior = toDel.prior
            container.removeValue(forKey: toDel.key)
        }
    }
}


```
##### 可以看出，LRU 的性能关键, 在于采用结构记录与保持

这里就是，链表的头部和尾部，一直都有更新。链表元素的顺序，符合 LRU

每次存取，都对链表做了更新 （ 除了取的时候，key 不存在 ）

方便调试，会更好。重写了 NSObject 的 `var description`.

最后的完整版本：

优化一点，
假的头节点和尾节点的链表关系结构，可以一开始就建好，不用以后每次写元素，都判断

```

class DLinkedNode: NSObject {
    let key: Int
    var val: Int
    var prior: DLinkedNode?
    var next: DLinkedNode?
    
    init(_ key: Int, value: Int) {
       self.key = key
        val = value
    }
    // 辅助调试 debug, 打印出信息的，方便看
    override var description: String{
        var result = String(val)
        var point = prior
        while let bee = point{
            result = "\(bee.val) -> " + result
            point = bee.prior
        }
        point = next
        while let bee = point{
            result = result + "-> \(bee.val)"
            point = bee.next
        }
        return result
    }
}




class LRUCache {
    // 怎样化 O ( n ) 为 O ( 1 ). 关心的状态，都用一个专门的指针，记录了
    var dummyHead = DLinkedNode(0, value: 0)
    var dummyTail = DLinkedNode(0, value: 0)
    var capacity: Int
    var container = [Int: DLinkedNode]()
    var hasCount: Int = 0

    init(_ capacity: Int) {
        self.capacity = capacity
          // 建立结构
          dummyHead.next = dummyTail
          dummyTail.prior = dummyHead
    }
    
    func get(_ key: Int) -> Int {
        // 有一个刷新机制
        if let node = container[key]{
            deleteNode(node)
            insertHead(node)
            return node.val
        }
        else{
            return -1
        }
    }
    
    func put(_ key: Int, _ value: Int) {
        if let node = container[key]{
            // 包含，就换顺序
            // 还有一个更新操作
            node.val = value
            deleteNode(node)
            insertHead(node)
        }
        else{
            if hasCount >= capacity{
                // 超过，就处理
                hasCount -= 1
                deleteTail()
            }
            hasCount += 1
            // 不包含，就插入头节点
            let node = DLinkedNode(key, value: value)
            insertHead(node)
            container[key] = node
        }
    }
    
    func insertHead(_ node: DLinkedNode){
        let former = dummyHead.next
        former?.prior = node
        dummyHead.next = node
        node.prior = dummyHead
        node.next = former
    }
    
    // 指针操作，最好还是弄个变量，接一下
    func deleteNode(_ node: DLinkedNode){
        node.prior?.next = node.next
        node.next?.prior = node.prior
        node.prior = nil
        node.next = nil
    }
    
    func deleteTail(){
        if let toDel = dummyTail.prior{
            toDel.prior?.next = dummyTail
            dummyTail.prior = toDel.prior
            container.removeValue(forKey: toDel.key)
        }
    }
}


```

