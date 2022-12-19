### 解题思路
- 第一遍循环获取链表的长度
- 长度对k进行取余(长5，移6，实际移1)
- 初始化两个指针， 余数作为初始时两个指针的间隔
- 两指针同时向后移动，当右指针到达末尾停止
- 此时左指针是尾节点，下一节点是头节点
- 右指针的下一节点指向原来的头结点
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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function (head, k) {
    let dummy = new ListNode(0)
    let count = 0, modk, R = head, L = head
    dummy.next = head
    let last = dummy
    while (last.next) {
        count++
        last = last.next
    }
    if(count === 0) return dummy.next
    modk = k % count
    while (modk--) {
        R = R.next
    }
    while (R.next) {
        R = R.next
        L = L.next
    }
    R.next = dummy.next
    dummy.next = L.next
    L.next = null
    return dummy.next
};
```