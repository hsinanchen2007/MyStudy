[用JS刷Leetcode](https://github.com/careteenL/data-structure_algorithm/blob/0816-leetcode/src/leetcode)

[解题思路-PPT形式](https://github.com/careteenL/data-structure_algorithm/blob/0816-leetcode/src/data-structure/reverse-linked-list.md)
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @think 递归
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
  function _reverse(head) {
    // 2. 从链表倒数第二个反向向前遍历
    // 2.1 倒数第二个节点的next的next置为当前节点
    // 2.2 倒数第三个节点的next的next置为当前节点
    // ...
    // 直到第一个节点
    if (head && head.next) {
      _reverse(head.next)
      head.next.next = head
      head.next = null
    } else { // 1. 找到链表尾巴，将其作为表头
        _reverse.head = head
    }
  }
  _reverse(head)
  return _reverse.head
};

```
