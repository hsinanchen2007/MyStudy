### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @desc 链表实现，链表示实现的版本与数组相比所有操作的时间复杂度、空间复杂度一样，但是对内存得使用效率更高
*/

class Node {
    constructor(value) {
        this.value = value
        this.next = null
    }
}

class MyCircularQueue {
    constructor(k) {
        // 链表的容量
        this.capacity = k
        // 头结点
        this.head = null
        // 尾结点
        this.tail = null
        // 链表的元素个数
        this.count = 0
    }
    Front() {
        if (this.isEmpty()) {
            return -1
        }
        return this.head.value
    }

    Rear() {
        if (this.isEmpty()) {
            return -1
        }
        return this.tail.value
    }

    enQueue(value) {
        if (this.isFull()) {
            return false
        }
        const newNode = new Node(value)
        if (this.isEmpty()) {
            this.head = newNode
            this.tail = newNode
        } else {
            // 只需要更新尾结点
            this.tail.next = newNode
            this.tail = newNode
        }
        this.count++
        return true
    }
    deQueue() {
        if (this.isEmpty()) {
            return false
        }
        this.head = this.head.next
        this.count--
        return true
    }

    isEmpty() {
        return this.count === 0
    }
    isFull() {
        return this.count === this.capacity
    }
}
```