### 解题思路
利用快慢指针，慢指针每次走一步，快指针每次走两步，当快指针的走到尾的时候，慢指针刚好走到中间。

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
    if (!head || !head.next) {
        return head;
    }
    var node1 = head;
    var node2 = head;
    while (node2 && node2.next) {
        node1 = node1.next;
        node2 = node2.next.next;
    }

    return node1;
};
```