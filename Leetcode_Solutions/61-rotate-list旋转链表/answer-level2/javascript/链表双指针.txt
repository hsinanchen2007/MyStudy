### Analyze

分析: 该题可以转化为从尾部向前数到第 k 个元素, 将该元素作为头节点, 同时将初始尾节点的下一个节点指向初始头节点。

1. 第一步: 遍历一遍链表得到初始尾结点 last;
2. 第二步: l 与 r 距离保持为 modK + 1;
3. 第三步: l 与 r 同时向右移动, 直到 r 为 null, 则 l 为要分割的元素;

> 此外如果链表长度为 0 或者链表长度与 k 相等时, 则链表实际上没有旋转交换位置。

```js
  l                r
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
                   .
                   .
                   l               r
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
  const dummy = new ListNode(0)
  dummy.next = head
  let count = 0
  let last = dummy
  while (last.next) {
    last = last.next
    count++
  }

  if (count === 0 || count === k) return dummy.next
  const modK = k % count
  let diff = modK + 1

  let l = dummy
  let r = dummy
  while (diff--) {
    r = r.next
  }

  while (r) {
    r = r.next
    l = l.next
  }

  last.next = dummy.next
  dummy.next = l.next
  l.next = null

  return dummy.next
}
```

### Sister Title

19

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)