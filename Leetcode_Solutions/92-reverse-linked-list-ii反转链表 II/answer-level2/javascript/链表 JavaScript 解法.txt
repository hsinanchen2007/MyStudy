### Analyze

```js
1 -> 2 -> 3 -> 4 -> 5
    (4 -> 3 -> 2)
```

该题是[206.Reverse_Linked_ List](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/206.Reverse_Linked_List/README.md) 的扩展, [m, n] 区间内指针翻转的思路同 206 题, 剩下的就是将 m 的 next 指向 n 指针的 next, 同时将排在 m 前面一位的指针的 next 指向 n。

会存在以下卡题的点:

* 最终返回的值怎么定;
* 如何借助中间变量;

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *   this.val = val;
 *   this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
  const originList = new ListNode(0)
  originList.next = head

  let listNode = originList

  for (let i = 0; i < m - 1; i++) {
    listNode = listNode.next
  }

  let prev = null
  let cur = listNode.next

  for (let i = 0; i < n - m + 1; i++) {
    let next = cur.next
    cur.next = prev
    prev = cur
    cur = next
  }

  // 将 m 的 next 指向 n 指针的 next, 同时将排在 m 前面一位的指针的 next 指向 n
  listNode.next.next = cur
  listNode.next = prev
  return originList.next
}
```

### Sister Title

206

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)