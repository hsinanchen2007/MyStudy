### 解题思路
用快慢指针，快的一次前进两格，慢的一次前进一格。

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
    if (!head || !head.next) return head;
    let slow = head, fast = head.next;
    while (fast) {
        slow = slow.next;
        if (fast.next) {
            fast = fast.next.next;
        } else {
            fast = null;
        }
    }
    return slow;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)