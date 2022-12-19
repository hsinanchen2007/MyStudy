### 解题思路
1. 双指针赛跑(比较有趣)
2. 用set记录走过的节点(比较常规)

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
 * @return {boolean}
 */
var hasCycle = function(head) {
    let p1 = head, p2 = head
    if (!head) {
        return false
    }
    while (true) {
        p1 = p1 ? p1.next : null
        p2 = p2 ? p2.next : null
        if (!p2) {
            return false
        } else {
            p2 = p2.next
        }
        if ((p2 === p1) && (p1 !== null)) {
            return true
        }
    }
}
```