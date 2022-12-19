```
class Node { // 节点
    let key: Int, value: Int
    var pre: Node?, next: Node?

    init(key: Int, value: Int) {
        self.key = key
        self.value = value
    }
}
```
```
class DoubleList { // 双向链表

    private let head: Node, tail: Node
    private var size = 0

    init() {
        head = Node(key: 0, value: 0)
        tail = Node(key: 0, value: 0)
        head.next = tail
        tail.pre = head
    }

    func add(_ node: Node) {

        let first = head.next

        first?.pre = node
        node.next = first

        node.pre = head
        head.next = node

        size += 1
    }

    func remove(_ node: Node) {
        node.pre?.next = node.next
        node.next?.pre = node.pre
        size -= 1
    }

    func removeLast() -> Node? {

        guard let result = tail.pre, size >= 1 else { return nil }
        remove(result)
        return result
    }

    func sizeOf() -> Int {
        return size
    }

}
```
```
class LRUCache {

    private let capacity: Int
    private var map = [Int: Node]()
    private let list = DoubleList()

    init(_ capacity: Int) {
        self.capacity = capacity
    }

    func get(_ key: Int) -> Int {
        if let node = map[key] {
            // 删除节点
            list.remove(node)
            // 移到链表第一个
            list.add(node)
            //返回value
            return node.value
        } else {
            return -1
        }
    }

    func put(_ key: Int, _ value: Int) {

        if let node = map[key]  {
            // 删除节点
            list.remove(node)
        }

        let newNode = Node(key: key, value: value)
        list.add(newNode)
        map[key] = newNode

        if list.sizeOf() > capacity, let last = list.removeLast()  {
            map.removeValue(forKey: last.key)
        }
    }
}
```