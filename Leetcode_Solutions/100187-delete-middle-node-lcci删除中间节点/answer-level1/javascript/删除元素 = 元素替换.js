### 解题思路
删除元素 其实就是把删除的那个元素(node)替换成下一个元素(node.next)

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
    let current = node;
    node.val = current.next.val;
    node.next = current.next.next;
};
```