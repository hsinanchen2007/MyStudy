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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    // Processing
    const chain = [head]
    let next = head.next
    while (next) {
        chain.push(next)
        next = next.next
    }
    // Guards
    if (n===chain.length) {
        return head.next
    }
    if (n===1) {
        chain[chain.length-2].next = undefined
        return head
    }
    // Slice
    const targetIndex = chain.length-n
    // console.log("INDEX:",targetIndex-1, targetIndex+1)
    if (targetIndex-1>=0 && targetIndex+1<chain.length) {
        // console.log(chain[targetIndex-1], chain[targetIndex+1])
        chain[targetIndex-1].next = chain[targetIndex+1]
    }
    return head
};
```
