### 解题思路
1.使用递归


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
    if (head === null || head.next === null) { 
    return head;
  }

  const next = head.next;
  const newHead = reverseList(next);

  head.next = null;
  next.next = head;

  return newHead;
};
```