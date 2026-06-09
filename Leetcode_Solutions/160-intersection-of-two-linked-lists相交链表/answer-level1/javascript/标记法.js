### 解题思路
标记法

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
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    while (headA) {
        headA.s = 1
        headA = headA.next
    }
    while (headB) {
        if(headB.s) return headB
        headB = headB.next
    }
    return null
};
```