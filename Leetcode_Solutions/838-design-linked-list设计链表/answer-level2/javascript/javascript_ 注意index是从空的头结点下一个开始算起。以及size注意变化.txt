

解题时，注意index = 0 是从头结点的下一个节点开始算起。

![微信截图_20200409215324.png](https://pic.leetcode-cn.com/14eaab9aa9e71113f2df2b336b423215f15dc352853cabde537fb491ce468f18-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200409215324.png)


   


- 删除，插入节点，就是基本的改变指针。
- 当前指针，是new出的对象，包括val，和next指针。

```
size = 3

{
    val: 0,   -> 头结点
    next: {
        val: 5,   -> 第一个节点，index = 0
        next: {
            val: 4,
            next: {
                val: 90,   -> 尾节点，index = 2,指针null
                next: null
            }
        }
    }
}
```



```
/**
 * Initialize your data structure here.
 */
var ListNode = function(value) {
    this.val = value
    this.next = null
}

var MyLinkedList = function() {
    this.size = 0
    this.head = new ListNode(0)
};

/**
 * Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
    console.log(JSON.stringify(this.head))
    if (index < 0 || index >= this.size) {
        return -1
    }
    var cur = this.head
    for (let i = 0; i <= index; i++) {
        cur = cur.next
    }
    return cur.val
};

/**
 * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
    const realyHead = new ListNode(val)
    realyHead.next = this.head.next
    this.head.next = realyHead
    this.size += 1
};

/**
 * Append a node of value val to the last element of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
    var cur = this.head
    for (let i = 0; i < this.size; i++) {
        cur = cur.next
    }
    var lasts = new ListNode(val)
    cur.next = lasts
    this.size += 1
};

/**
 * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
    if (index <= 0) {
        this.addAtHead(val)
    } else if (index > this.size) {
        return
    } else if (index === this.size) {
        this.addAtTail(val)
    } else {
        let cur = this.head
        for (let i = 0; i < index; i++) {
            cur = cur.next
        }
        var node = new ListNode(val)
        node.next = cur.next
        cur.next = node
        this.size += 1
    }

};

/**
 * Delete the index-th node in the linked list, if the index is valid. 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {
    if (index >= 0) {
        let cur = this.head
        for (let i = 0; i < index; i++) {
            cur = cur.next
        }
        if (index < this.size - 1) {
            cur.next = cur.next.next
            this.size -= 1
        } else if (index == this.size - 1) {
            cur.next = null
            this.size -= 1
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
```