### 解题思路
此处撰写解题思路

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
 * @return {ListNode}
 */
var middleNode = function(head) {
    if (!head.next) return head;
    let mid = head;
    mid.flag = false;
    while (head) {
        head = head.next;
        if (mid.flag) {
            mid = mid.next;
        } else {
            mid.flag = true;
        }
    }
    return mid;
};
```