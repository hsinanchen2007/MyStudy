### Analyze

对于删除链表节点的题目, 我们需要知道需删除链表节点的上一个节点。那如何找到需要删除节点的上一个节点呢?

* 思路一: 遍历一遍链表得到链表个数 sum, 再次遍历链表则 `sum - n - 1` 表示从正向数过来需删除的链表节点的上一个节点的位数;
  * 缺点: 这样需要两次遍历;
* 思路二: 使用双指针的思想确认要删除的节点;

此外从题目的例子可以得到的线索:
  * n 是从 1 开始的(不是从 0 开始);

```js
1 -> 2 -> 3 -> 4 -> 5 -> null
                .
                .
第一步: l 与 r 的距离为 n + 1;
  l                r
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
                .
                .
第二步: 始终保持 l 与 r 的距离为 n + 1, 向右移动, 直到 r 为 null, 此时 l 的位置就是要删除节点上一个的位置。
                   l               r
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
```

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  const dummy = new ListNode(0)
  dummy.next = head
  let l = dummy
  let r = dummy
  let offset = n + 1

  while (offset--) {
    r = r.next
    if (offset > 1 && r === null) {
      return dummy.next
    }
  }

  while (r) {
    r = r.next
    l = l.next
  }

  l.next = l.next.next

  return dummy.next
}
```

![](https://pic.leetcode-cn.com/4c6122bfa6034ed62f99a12831bdb9c1339853b0e1bf910d48b0a06fe1cba87d.jpg)

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)
