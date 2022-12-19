### 解题思路
快慢双指针

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
    let first = head;
    let second = head;
    while (second && second.next) {
        second = second.next.next;
        first = first.next;
    }
    return first;
};
```