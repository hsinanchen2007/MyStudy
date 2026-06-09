### 解题思路
k - 1

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
 * @param {number} k
 * @return {number}
 */
var kthToLast = function (head, k) {
    let result = head
    for (let i = 0; i < k - 1; i++) {
        head = head.next
    }
    while (head && head.next) {
        result = result.next
        head = head.next
    }
    return result.val
};
```