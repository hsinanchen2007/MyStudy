### Analyze

```js
       cur    next
Input:  1  ->  2  ->  3  ->  4  ->  5  ->  NULL
       prev   cur    next
        1  ->  2  ->  3  ->  4  ->  5  ->  NULL
                      .
                      .
                            prev   cur    next  遍历完成后, 如果此时是奇数位则将 cur 的指针指向偶数列表。
        1  ->  2  ->  3  ->  4  ->  5  ->  NULL


Output: 1  ->  3  ->  5  ->  2  ->  4  ->  NULL
```

* 将 prev 的 next 指向 next;
* 如何将奇数链表与偶数链表进行链接(末尾的链表可能为奇数位也可能为偶数位)?

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
 * @return {ListNode}
 */
var oddEvenList = function(head) {
  if (!head) return head
  const list = new ListNode(0)
  list.next = head
  const odd = list.next
  const even = odd.next

  let prev = null
  let cur = list.next
  let next = cur.next
  let count = 1

  while (next) {
    prev && (prev.next = next)
    prev = cur
    cur = next
    next = cur.next
    count++
  }

  if (count % 2 === 1) {
    prev && (prev.next = null)
    cur.next = even
  } else {
    prev.next = even
  }

  return odd
}
```

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)