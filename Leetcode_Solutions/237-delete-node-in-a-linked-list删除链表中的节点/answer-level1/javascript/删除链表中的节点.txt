### 解题思路

将node.next合到node中

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
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function(node) {
    // node.val = node.next.val
    // node.next = node.next.next
    Object.assign(node, node.next);
};
```