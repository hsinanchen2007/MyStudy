### 解题思路

使用 `WeakMap` 存入已经遍历的数据，每次遍历前查看 `WeakMap` 有没有当前有的 `node` 节点，有则返回节点 `node` ; 遍历完成后没有的话 返回那 `null`

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
var detectCycle = function(head) {
  if(!head) return null
  var map = new WeakMap()
  while(head.next) {
    if(map.get(head.next)) {
      return head.next
    }
    map.set(head, true)
    head = head.next
  }
  return null
};
```