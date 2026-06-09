### 解题思路
见注释。

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
 * @return {ListNode}
 */
var middleNode = function(head) {
    if(head === null || head.next === null) return head;
    let slow = head;
    let fast = head;
    while(fast.next !== null && fast.next.next !== null) {
        fast = fast.next.next;
        slow = slow.next;
    }
    // 退出while循环的条件有两种情况：
    // 1. fast.next为null，说明链表包含了奇数个节点，此事slow就指向最中间的节点
    // 2. fast.next不为null，说明链表包含了偶数个节点，此时slow指向处于最中间的做左边的一个节点，按照要求应该返回slow.next
    return fast.next !== null ? slow.next : slow;
};
```