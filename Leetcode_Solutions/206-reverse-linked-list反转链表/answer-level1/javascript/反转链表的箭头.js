定义三个变量，反转链表的箭头即可

```
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
    var pre = null
    var cur = head
    while(cur){
        temp = cur.next
        cur.next = pre
        pre = cur
        cur = temp
    }
    return pre
};
```
