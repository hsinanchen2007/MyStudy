### 解题思路
这个应该是最常规的解法了，用三个指针p1 p2 p3，p3在最前面走，然后不断地让p2指向p1

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
var reverseList = function (head) {
  if (!head || !head.next) return head;

  let p1 = head, p2 = head.next;

// 处理链表长度为2的情况
  if (!p2.next) {
    p2.next = p1;
    p1.next = null;
    return p2;
  }
  let p3 = p2.next;
  head.next = null;
  while(p3) {
    p2.next = p1;
    p1 = p2;
    p2 = p3;
    p3 = p3.next;
  }
  p2.next = p1;
  return p2;
};
```