### 解题思路
写的不多就不够熟练啊

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
var mergeTwoLists = function (l1, l2) {
    let head = c = new ListNode(null)
    while (l1 && l2) {
        if (l1.val <= l2.val) {
            c.next = l1
            l1 = l1.next
        } else {
            c.next = l2
            l2 = l2.next
        }
        c = c.next
    }
    if(l1){
        c.next = l1
    }
    if(l2){
        c.next = l2
    }
    return head.next
};
```