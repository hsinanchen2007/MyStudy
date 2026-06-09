### 解题思路
此处撰写解题思路

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
    if (head == null || head.next == null) {
            return false
        }

        let slow = head
        let fast = head

        while (fast != null && fast.next != null) {
            slow = slow.next
            fast = fast.next.next
            if (slow == fast) {
                return true
            }
        }
        return false
};


```
经典的龟兔赛跑问题