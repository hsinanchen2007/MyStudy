### 解题思路
快慢指针找出中心，顺便反转之前的链表

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let slow = head;
    let fast = head;
    let prev = null;
    let nextTmp;
    while (fast !== null && fast.next !== null) {
        fast = fast.next.next;
        nextTmp = slow.next;
        slow.next = prev;
        prev = slow;
        slow = nextTmp;
    }
    if (fast !== null) slow = slow.next; // 奇数
    while (slow !== null) {
        if (prev.val !== slow.val) return false;
        slow = slow.next;
        prev = prev.next;
    }
    return true;
};
```