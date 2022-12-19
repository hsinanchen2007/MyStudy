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
var reverseList = function(head) {
    if (!head) {
        return null;
    }
    var p = head;
    while(p.next) {
        var pre = p.next;
        p.next = p.next.next;
        pre.next = head;
        head = pre;
    }
    return head;
};
```