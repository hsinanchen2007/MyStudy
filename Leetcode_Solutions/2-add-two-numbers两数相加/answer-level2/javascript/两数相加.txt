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
    let res = prev = new ListNode(null), left = 0, carry = 0;
    while (l1 !== null || l2 !== null || carry) {
        let sum = (l1 !== null ? l1.val : 0) + (l2 !== null ? l2.val : 0) + carry;
        left = sum % 10;
        carry = Math.floor(sum / 10);
        prev.next = new ListNode(left);
        prev = prev.next;
        l1 = l1 && l1.next !== null ? l1.next : null;
        l2 = l2 && l2.next !== null ? l2.next : null;
    }
    return res.next;
};