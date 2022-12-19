### 解题思路

这道题鸡贼的是只给出了一个被删除的节点，我还以为是出 ``BUG`` 了，其实这里应该删除的是链表的节点的值才对，直接看代码就能懂了。

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
    node.val = node.next.val
    node.next = node.next.next
};
```