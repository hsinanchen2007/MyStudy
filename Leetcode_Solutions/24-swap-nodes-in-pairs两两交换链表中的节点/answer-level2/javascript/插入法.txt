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
```
var swapPairs = function(head) {
    let childNode = head;
    let pre =  null;
    while(childNode && childNode.next) {
        let temp = new ListNode(childNode.val);
        temp.next = childNode.next.next;
        childNode.next.next = temp;
        if (pre) pre.next = childNode.next;
        else head = head.next;
        pre = temp;
        childNode = temp.next;
    }
    return head;
};

```