### 解题思路

翻转链表，即后继节点变前驱节点，

所以先定义一个pre = null,cur = head  
然后在while循坏(当cur为null退出)中依次改变他们的next即可完成

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
  if (!head || !head.next) return head; //空链表或只一个节点

  let pre = null
 

  let cur = head
  
  while (cur) {
    let next = cur.next
    cur.next = pre
    pre = cur
    cur = next
  }
   return pre
};
```