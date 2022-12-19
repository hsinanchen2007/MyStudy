### 解题思路
双指针，长指针代表链表长度length，求倒数k的值，即length-k位置的值

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
 * @return {number}
 */
var kthToLast = function (head, k) {
  let kn = head;
  let ln = head;
  let index = 0;
  while (kn) {
    index++;
    if (index > k) {
      ln = ln.next;
    }
    kn = kn.next;
  }
  return ln.val
};
```