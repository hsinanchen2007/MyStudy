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
let newHead = [];
var reverseList = function(head) {
    /*
    let newHead = null, temp;
    // 空间复杂度O(n)，时间复杂度O(n)
    while(head != null) {
        temp = new ListNode(head.val);
        temp.next = newHead;
        newHead = temp;
        head = head.next;
    }

    return newHead;
    */

    /*
    // 空间复杂度O(1)，时间复杂度O(n)
    let newHead = null, temp, next;
    while(head != null) {
        next = head.next;
        head.next = newHead;
        newHead = head;
        head = next;
    }

    return newHead;
    */

    // 递归解法
    if (!head) return null;
    let tail = recur(head);
    tail.next = null;

    return newHead;
};

var recur = function (head) {
    if (head.next != null) {
        recur(head.next).next = head;
        return head;
    } else {
        newHead = head;
        return head;
    }
}
```
