### 解题思路
此处撰写解题思路

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {

    let dummyHead = {}, cur = dummyHead,
        p = l1, q = l2

    let carry = 0 // 进位
    while (p || q) {
        let x = p ? p.val : 0
        let y = q ? q.val : 0

        let sum = x + y + carry
        carry = sum > 9 ? 1 : 0

        cur = cur.next = new ListNode(sum % 10)

        if (p) p = p.next
        if (q) q = q.next
    }

    if (carry)
        cur = cur.next = new ListNode(1)

    return dummyHead.next
};
```