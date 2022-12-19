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
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {

    if (!head) return null

    let less = {}, more = {},
        p = less, q = more, cur = head

    while (cur) {
        if (cur.val < x)
            p = p.next = cur
        else
            q = q.next = cur
        cur = cur.next
    }

    p.next = more.next
    q.next = null

    return less.next
};
```