### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyLinkedList = function() {
    head = tail = null;
    size = 0;
};

/**
 * Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {

    if (index < 0 || index >= size) return -1;
    
    let cur = head; 
    for (let i = 0; i < index; i++)
        cur = cur.next;

    return cur.val;
};

/**
 * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
    if (!head) {
        head = new ListNode(val);
        tail = head;
    } else {
        let node = new ListNode(val)
        node.next = head;
        head = node;
    }
    size++;
};

/**
 * Append a node of value val to the last element of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
    if (!head) {
        head = new ListNode(val);
        tail = head;
    } else {
        tail.next = new ListNode(val);
        tail = tail.next;
    }
    size++;
};

/**
 * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
    if (index > size) return;
    if (index <= 0) {
        this.addAtHead(val);
        return;
    }

    let prev = head;
    for (let i = 0; i < index - 1; i++)
        prev = prev.next;

    let node = new ListNode(val);
    node.next = prev.next;
    prev.next = node;
    if (index == size) tail = node;
    size++;
};

/**
 * Delete the index-th node in the linked list, if the index is valid. 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {

    if (index < 0 || index >= size) return;

    if (index === 0) {
        head = head.next;
        size--;
        return;
    }

    let prev = null, cur = head;
    for (let i = 0; i < index; i++) {
        prev = cur;
        cur = cur.next;
    }
    
    prev.next = cur.next;
    if (index === size - 1) tail = prev;
    size--;
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