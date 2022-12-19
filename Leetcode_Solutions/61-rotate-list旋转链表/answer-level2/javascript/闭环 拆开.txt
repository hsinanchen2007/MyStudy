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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
  if(!head) {
      return null;
  }
  if(!k) {
      return head;
  }
  let cnt = 1;
  let ori_head = head;
  while(head.next) {
      head = head.next;
      cnt++;
  }
  
  head.next = ori_head;
  let step = cnt - k%cnt - 1  // 这一步 没太看明白
  console.log('k', cnt);
  while(step) {
      ori_head = ori_head.next;
      step--;
  }
  let new_head = ori_head.next;
  ori_head.next = null;

  return new_head;
};
```