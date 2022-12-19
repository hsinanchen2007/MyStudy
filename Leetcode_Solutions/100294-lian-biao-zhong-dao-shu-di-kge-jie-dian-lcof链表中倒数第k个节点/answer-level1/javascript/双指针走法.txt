### 解题思路
双指针 快指针(fast)先走k布, 再快慢指针一起走, 直到fast为null, 这时候的慢指针就是返回的链表

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
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    let fast = head;
    let slow = head;
    let i = 0;
    while(fast !== null) {
        if (i < k) {
            fast = fast.next; 
        } else {
            fast = fast.next; 
            slow = slow.next;
        }
        i++;
    }
    return slow;
};
```