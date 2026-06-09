### 解法一
三步，第一步快慢指针找到中间节点，把链表分成前后两部分；第二步将后半部分链表反转；第三步，将两部分链表合并

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {
    if (!head || !head.next) {
        return 
    }
    // 1. 快慢指针找到链表中点
    let node1 = head
    let node2 = head.next
    while (node2 && node2.next) {
        node1 = node1.next
        node2 = node2.next.next
    }
    // 后半部分链表
    node2 = node1.next
    // // 注意，这一步很重要，node1.next = null，之后node1 = head，才能使得node1只保留链表前半部分
    node1.next = null
    node1 = head
    // 2. 翻转后半部分链表
    let prev = null
    let cur = node2
    while (cur) {
        let temp = cur.next
        cur.next = prev
        prev = cur
        cur = temp 
    }
    // 3.前后两部分链表合并(前后部分长度相同或者后半部分多一个
    node2 = prev
    while (node2) {
        let next1 = node1.next
        let next2 = node2.next
        node1.next = node2
        node2.next = next1
        node1 = next1
        node2 = next2
    }
}
```

### 解法二
借助数组特性

### 代码
```javascript
var reorderList = function(head) {
    if (!head || !head.next) {
        return
    }
    // temp1保存链表节点原来的顺序
    const temp1 = []
    while (head) {
        temp1.push(head)
        head = head.next
    }
    // temp2保存链表节点交换顺序后的顺序
    const temp2 = []
    const len = temp1.length
    for (let i = 0; i < len; i++) {
        temp2.push(temp1[i])
        if (i !== len - i - 1) {
            temp2.push(temp1[len - i - 1])
        }
    }
    // 将各个节点next指针联系起来
    const node = temp2[0]
    let cur = node
    for (let j = 1; j < len; j++) {
        cur.next = temp2[j]
        cur = cur.next
        cur.next = null
    }
    head = node
};
```