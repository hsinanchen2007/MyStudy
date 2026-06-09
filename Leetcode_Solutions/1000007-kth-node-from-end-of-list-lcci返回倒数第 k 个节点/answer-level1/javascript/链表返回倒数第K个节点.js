### 解题思路
链表双指针问题，快指针先走k步，然后双指针一起走

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
 * @return {number}
 */
var kthToLast = function(head, k) {
    let r=head;
    //head先走k步
    let count=0
    while(++count<=k){
        head=head.next
    }
    //俩指针一起走
    while(head){
        head=head.next
        r=r.next
    }
    return r.val
};
```