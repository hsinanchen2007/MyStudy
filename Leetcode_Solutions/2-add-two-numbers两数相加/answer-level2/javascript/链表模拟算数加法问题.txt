```
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
var addTwoNumbers = function(l1, l2) {
    let l1arr = [];
    let l2arr = [];
    let nodes = new ListNode(0);
    let node = nodes;
    let car = 0;
    while(l1 || l2) {
        node.next = new ListNode(0);
        node = node.next;
        let val1 = l1 ? l1.val : 0;
        let val2 = l2 ? l2.val : 0;
        let sum = val1 + val2 +car;
        node.val = sum % 10;
        car = parseInt(sum / 10);
        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
    }
    // 最高位产生进位
    if (car) {
        node.next = new ListNode(0);
        node = node.next;
        node.val = car;
    }
    nodes = nodes.next;
    return nodes;
};
```
