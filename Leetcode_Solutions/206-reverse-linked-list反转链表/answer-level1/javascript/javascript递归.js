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
 * @return {ListNode}
 */
var reverseList = function(head) {
    if (head === null) return head;
    if (head.next === null) return head;

    let last = reverseList(head.next);
    head.next.next = head;
    head.next = null;

    return last;
};
```