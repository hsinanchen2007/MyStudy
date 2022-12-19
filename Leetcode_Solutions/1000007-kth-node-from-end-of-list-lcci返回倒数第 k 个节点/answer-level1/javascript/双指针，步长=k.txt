### 解题思路
双指针，步长=k

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
    let myk = head, i = 0;
    while(head){
        i++;
        if(i>k){
            myk=myk.next;
        }
        head = head.next;
    }
    return myk.val;
};
```