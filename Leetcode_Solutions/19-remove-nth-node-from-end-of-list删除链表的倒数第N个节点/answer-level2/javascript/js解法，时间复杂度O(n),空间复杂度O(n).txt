### 解题思路
一次遍历放入数组即可，然后根据n和数组长度来删除节点。

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  if (!head || !n) {
    return head
  }
  let res = []
  let p = head
  while(p) {
    res.push(p)
    p = p.next
  }
  let len = res.length
  if (n >= len) {
    if (n === len) {
      return head.next
    }
    return head
  }
  res[len - n - 1].next = res[len - n].next

  return res[0]
};
```