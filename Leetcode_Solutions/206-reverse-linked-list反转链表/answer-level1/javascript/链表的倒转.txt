### 解题思路
此处撰写解题思路

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
  let pre = null; 
  let cur = head;
  while(cur!==null) {
      let temp = cur.next;
       cur.next = pre;
       pre = cur;
       cur = temp;
  }
  return pre;
};
```