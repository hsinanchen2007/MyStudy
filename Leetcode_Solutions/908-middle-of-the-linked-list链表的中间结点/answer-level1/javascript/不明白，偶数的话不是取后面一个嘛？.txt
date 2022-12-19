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
var middleNode = function(head) {
      var cont = 0;
      var tep = head
      var se = head;
      while (tep) {
         tep.n = cont;
         cont++;
         tep = tep.next;
      }
      var m = (~~(cont/2))
      while(se.n !== (m)){
          se = se.next;
      }
      return se;
};
```