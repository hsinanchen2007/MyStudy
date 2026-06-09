## 解题思路

采用迭代的方式，使用两个变量，一个变量保存下一位待保存的ListNode

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
  let pre = null
  let curr = head
  while (curr !== null) {
    let nextTemp = curr.next
    curr.next = pre
    pre = curr
    curr = nextTemp
  }
  return pre
};
```