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
var getKthFromEnd = function(head, k) {
   let start = head;
   let cur = head;
   let i=0;
   while(cur!==null) {
     if(i>=k) {
         start = start.next;
     }
     cur = cur.next;
     i++;
   }
   return start;
};
```