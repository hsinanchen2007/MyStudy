### 解题思路
此处撰写解题思路
1. 利用快慢指针，快指针每次走两步，慢指针每次走一步，当快指针走到链尾时，慢指针就指向中点了。

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
 if (!head) return head
  if (!head.next) return head
  let slow = head
  let quick = head
  while(quick && quick.next) {
    quick = quick.next.next
    slow = slow.next
  }
  return slow
};
```