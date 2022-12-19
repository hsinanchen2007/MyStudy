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
var deleteDuplicates = function(head) {
    if(!head) return null
    if(!head.next) return head
    const map = new Map()
    let fake = new ListNode(Infinity)
    fake.next = head
    let cur = head
    let pre = fake
    while(cur) {
        let tail = cur
        if(cur.next && (cur.next.val === cur.val)){
            tail = cur.next
            while(tail && (tail.val === cur.val)){
                tail = tail.next
            }
        }
        if(cur !== tail) {
            pre.next = tail
            cur = tail
        } else {
            pre = cur
            cur = cur.next
        }
    }
    return fake.next
};
```
