```
// time: 80ms(32.79%) memory: 34MB(25.30%)
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
    let arr = [];
    let next = head;

    while(next) {
        arr.push(next.val);
        next = next.next;
    }
    arr.splice(arr.length - n, 1);

    let res = new ListNode(null);
    for (let i = arr.length - 1; i >= 0; i--) {
        let temp = new ListNode(null);
        res.val = arr[i];
        temp.next = res;
        res = temp;
    }

    return res.next;
};
```