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
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {
  if(head.val ===val) {
    return head.next;
  }
  let pre = head;
  let current = head.next;
  while (current!==null&&current.val !==val) {
      pre = current;
      current = current.next;
  }
  if(current!==null) {
      pre.next=current.next;
  }
  return head;
};
```