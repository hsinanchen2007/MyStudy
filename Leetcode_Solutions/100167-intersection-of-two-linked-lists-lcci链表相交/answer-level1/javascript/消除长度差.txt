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
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let a = headA
    let b = headB 
    let flag = 0
    while(a != b){
      if(a == null) {
        a = headB;
        // flag++
      }
      else a = a.next
      if(b == null) {
        b = headA
        // flag++
      }
      else b = b.next
    }
    return a
};
```