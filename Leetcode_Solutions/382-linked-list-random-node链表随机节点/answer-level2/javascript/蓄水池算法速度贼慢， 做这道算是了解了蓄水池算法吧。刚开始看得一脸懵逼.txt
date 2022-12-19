```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
 * @param {ListNode} head
 */
var Solution = function(head) {
    this.head = head
};

/**
 * Returns a random node's value.
 * @return {number}
 */
Solution.prototype.getRandom = function() {
    let cur = this.head.next
    let val = this.head.val
    let i = 2
    while(cur) {
        if(randomInt(i) % i === 0) val = cur.val
        cur = cur.next
        i++
    }
    return val
};

function randomInt(i) {
    return Math.floor(Math.random() * i) + 1
}

```
