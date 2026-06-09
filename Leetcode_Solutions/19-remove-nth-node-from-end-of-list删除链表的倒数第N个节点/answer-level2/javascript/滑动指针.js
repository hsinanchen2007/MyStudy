### 解题思路
两个指针，A,B，A指针走到N的时候，B指针开始走，这样A到头的时候，B就是倒数第N个，然后操作删除即可

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
  const dummy = new ListNode(0)
  dummy.next = head
  let l = dummy
  let r = dummy
  let temp = 0
  while (r) {
    r = r.next
    temp +=1
    if (temp > n + 1){
        l = l.next
    }
  }

  l.next = l.next.next

  return dummy.next
}
```