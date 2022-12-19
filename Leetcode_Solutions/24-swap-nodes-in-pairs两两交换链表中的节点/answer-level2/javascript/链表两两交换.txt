### 解题思路
链表问题，需要考虑的是到底要存多少指针。循环的时候，两个指针用来交换，剩下一个指针作为游标像后移动。

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
//pre {} a 1 b 2
//1->2->3->4->5 => 2->1->3->4->5
//pre 1 a 3 b 4
//2->1->3->4->5 => 2->1->4->3->5
var swapPairs = function(head) {
  let self = {}
  let pre = self
  pre.next = head
  while (pre.next && pre.next.next) {
    let a = pre.next   // a = 1          a = 3       新a设为老a的next
    let b = a.next    // b = 2           b = 4       新b设为新a的next
    a.next = b.next
    b.next = a        // 1<->2           3<->4       a、b反转
    pre.next = b      // pre -> 2        1->4        将pre的指针指向反转之后的b点
    pre = a           // pre = 1         pre = 3     pre改为反转之后的a点
  }
  return self.next
};
```