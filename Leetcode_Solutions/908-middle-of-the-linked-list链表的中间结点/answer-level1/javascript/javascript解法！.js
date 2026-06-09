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
 * @return {ListNode}
 */
var middleNode = function (head) {
    let len = 1, cur = head, tmp = 0, ans = 1
    while (cur.next != null) {
        cur = cur.next
        len++
    }
    if (len % 2 === 0) {
        tmp = len / 2 + 1
    } else {
        tmp = Math.round(len / 2)
    }
    cur = head
    while (cur.next != null) {
        cur = cur.next
        if (++ans === tmp) {
            return cur
        }
    }
    return cur
};
```
