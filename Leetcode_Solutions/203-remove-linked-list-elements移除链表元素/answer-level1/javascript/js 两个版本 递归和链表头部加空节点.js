``` javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * 版本一：
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
  let cur = head
  let newhead = new ListNode()
  newhead.next = head
  let pre = newhead
  while (cur) {
      if (cur.val === val) {
          pre.next = cur.next
      } else {
          pre = cur
      }
      cur = cur.next
  }
  return newhead.next
};

/**
 * 版本二 精妙的递归
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements2 = function(head, val) {
  if(!head) return head
  head.next = removeElements(head.next, val)
  return head.val === val ? head.next : head
};
```