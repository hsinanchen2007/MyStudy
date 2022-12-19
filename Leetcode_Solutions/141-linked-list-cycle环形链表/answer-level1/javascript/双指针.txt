### 解题思路
若是环形链表快指针总会和慢指针相遇

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
 * @return {boolean}
 */
var hasCycle = function(head) {
    if(head === null) return false
    let slow = head, fast = head.next
    while(fast && fast.next) {
        if (slow.next === fast.next.next) return true
        slow = slow.next
        fast = fast.next.next
    }
    return false
};
```