### 解题思路
此处撰写解题思路
方法：数组
链表的缺点在于不能通过下标访问对应的元素。因此我们可以考虑对链表进行遍历，同时将遍历到的元素依次放入
数组A中。如果我们遍历到了N个元素，那么链表以及数组的长度也为N，对应的中间节点即为A[N/2]
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
    let A = [head];
    while(A[A.length - 1].next !== null)
     A.push(A[A.length-1].next);
     return A[Math.trunc(A.length /2)]
};
```
时间复杂度O(N)),其中N是给定链表的节点数目