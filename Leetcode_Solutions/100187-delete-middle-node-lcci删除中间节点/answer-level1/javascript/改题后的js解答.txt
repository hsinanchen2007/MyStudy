### 解题思路
题目改了，先通过n找到被删的node，再进行删除

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
 * @param {number} n
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function(node, n) {
    while(node){
        if(node.val === n){
            node.val = node.next.val
            node.next = node.next.next
        }
        node = node.next
    }
    

};
```