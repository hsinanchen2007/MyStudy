### 解题思路

非递归法 
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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    var ans = prev =  new ListNode()
    while(l1 || l2) {
        if(l1 && l2) {
            if(l1.val <= l2.val) {
                prev.next = l1
                prev = prev.next
                l1 = l1.next
            } else {
                prev.next = l2
                prev = prev.next
                l2 = l2.next
            }
        } else{
            l1 ? prev.next = l1 : prev.next = l2
            break
        } 
    }
    return ans.next
};
```