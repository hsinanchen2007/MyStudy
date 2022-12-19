
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
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    while(head != null && head.val == val) {
        let delNode = head
        head = head.next
        delNode.next = null
    }

    if(head == null) return null

    var prev = head

    while(prev.next != null) {
        if(prev.next.val == val) {
            let delNode = prev.next
            prev.next = delNode.next
            delNode.next = null
        } else {
            prev = prev.next
        }
    }
    return head
};
```