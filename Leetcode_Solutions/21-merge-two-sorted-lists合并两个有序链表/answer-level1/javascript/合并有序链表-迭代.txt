### 解题思路

主要被坑在l1 !== null && l2 !== null上

一个结束循环后，直接在尾部添加另个的值

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
    let result = new ListNode(-1);
    let p1 = result;
    while(l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            p1.next = l1;
            l1 = l1.next;
        } else {
            p1.next = l2;
            l2 = l2.next;
        }
        p1 = p1.next;
    }
    p1.next = l1 == null ? l2 : l1;
    return result.next;
};
```