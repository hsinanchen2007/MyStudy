### 解题思路
为每个节点记录pos，如果遍历过程遇到之前的pos，证明含有环
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
    let pos = 0
    let cur = head
    while (cur) {
        if (cur.pos === undefined) {
            cur.pos = pos
            pos ++
            cur = cur.next
        } else {
            return true
        }
    }
    return false
};
```