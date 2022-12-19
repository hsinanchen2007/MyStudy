### 解题思路
分析题意，整个链表向右移动 k 位，等价于：一个首位首尾相连的链表，长度为 len， 某个指针指向 head，将其从 head 前 k + 1 位断开，以 head 前 k 位为新的链表头。

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
var rotateRight = function(head, k) {
    if (!k || !head) return head;
    let len = 1, prev = head;
    // 统计链表长度
    while (prev.next) {
        prev = prev.next;
        ++len;
    }
    prev.next = head;
    const offset = len - (k % len);
    for (let i = 0; i < offset; ++i) {
        prev = prev.next;
    }
    const dump = prev.next;
    prev.next = null;
    return dump;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)