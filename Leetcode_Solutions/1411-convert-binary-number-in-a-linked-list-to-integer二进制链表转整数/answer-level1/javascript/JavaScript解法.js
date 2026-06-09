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
 * @return {number}
 */
var getDecimalValue = function(head) {
    let temp = '';
    while(head) {
        temp = temp + head.val;
        head = head.next;
    }
    return parseInt(temp, 2);
};
```
