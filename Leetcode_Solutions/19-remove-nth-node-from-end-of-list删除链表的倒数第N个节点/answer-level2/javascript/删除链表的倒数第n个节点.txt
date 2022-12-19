1. 利用快慢指针，快指针先走n个节点，然后快慢指针一起走即可。
2. 注意，题目中说n的值都是合法的，但是在现实中，代码的健壮性还是要保证的，所以要判断n是否不合法：
   - n为小于或等于0的数
   - n超出了链表的长度

### 代码如下
```
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
var removeNthFromEnd = function (head, n) {
  // 判断n是否小于或等于0，其实现实代码中，这里我会报错
  if (!head || !n) return head
  // 快慢指针
  let slow = head
  let quick = head
  let temp = null
  n = n-1
  while(quick && n) {
    quick = quick.next
    n--
  }
  // 判断n是否大于链表的长度，其实现实代码中，这里我会报错
  if (!quick) {
    return head
  }
  while(quick.next) {
    temp = slow
    quick = quick.next
    slow = slow.next
  }
  if (temp) {
    temp.next = slow.next
  } else {
    head = slow.next
  }
  return head
};
```
