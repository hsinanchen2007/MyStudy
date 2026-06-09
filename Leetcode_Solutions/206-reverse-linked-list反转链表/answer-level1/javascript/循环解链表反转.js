### 解题思路

关键是要想清楚 如何判断循环结束 和 返回值应该是什么

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
 * @return {ListNode}
 */
var reverseList = function(head) {
    let p = head
    let prev = null
    while (p) {
        let tmp = p
        p = p.next
        tmp.next = prev
        prev = tmp
    }

    return prev
};
```